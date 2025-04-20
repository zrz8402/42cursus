#include "Logger.hpp"
#include "ConnectionManager.hpp"

int ConnectionManager::epoll_socket = 0;

ConnectionManager::ConnectionManager() {}

ConnectionManager::~ConnectionManager() {

    for (
        std::map<int, Connection>::iterator iter = this->connections.begin();
        iter != this->connections.end();
        ++iter
    ) {
        close_connection(iter->first);
    }

}

Connection *ConnectionManager::find_connection(int fd) {

    std::map<int, Connection>::iterator iter = this->connections.find(fd);

    if (iter != this->connections.end()) {
        return &(iter->second);
    }

    return (NULL);

}

int ConnectionManager::open_connection(int client_socket, ServerConfig::ServerConfigData &config) {

    int flags = fcntl(client_socket, F_GETFL, 0);

    if (flags < 0 || fcntl(client_socket, F_SETFL, flags | O_NONBLOCK) < 0) {
        close(client_socket);
        return (-1);
    }

    this->connections[client_socket] = Connection(client_socket, config);
    this->connections[client_socket].clear();

    epoll_event trigger;

    trigger.events = EPOLLIN;
    trigger.data.fd = client_socket;
    epoll_ctl(this->epoll_socket, EPOLL_CTL_ADD, client_socket, &trigger);

    return connections.size();

}

bool ConnectionManager::close_connection(int client_socket) {

    std::map<int, Connection>::iterator iter = this->connections.find(client_socket);

    epoll_ctl(epoll_socket, EPOLL_CTL_DEL, client_socket, NULL);
    close(client_socket);

    if (iter != connections.end()) {
        connections.erase(client_socket);
    }

    return (true);

}

size_t ConnectionManager::remove_expired_connections() {

    size_t count = 0;
    time_t current_timestamp = time(NULL);

    for (
        std::map<int, Connection>::iterator iter = this->connections.begin();
        iter != this->connections.end();
        ++iter
    ) {
        if (iter->second.is_connection_expired(current_timestamp)) {
            close_connection(iter->second.get_socket());
            count++;
        }
    }

    return (count);

}

size_t  ConnectionManager::add_server(int fd, ServerConfig::ServerConfigData server) {

    if (this->server_data.find(fd) != this->server_data.end()) {
        throw std::runtime_error("ConnectionManager try to overwrite existing sockets");
    }

    this->server_data[fd] = server;
    return this->server_data.size();

}

size_t  ConnectionManager::add_server(ServerConfig::ServerConfigData server) {
    this->config_lists.push_back(server);
    return this->config_lists.size();
}

bool ConnectionManager::socket_read(int fd) {

    char buffer[SOCKET_READ_BUFFER_SIZE];
    size_t buffer_size = SOCKET_READ_BUFFER_SIZE - 1;
    Connection *connection = get_connection_from_fd(fd);

    // Processing done
    if (connection->get_header_status() && connection->get_request_status()) {
        return (true);
    }

    try {
        
        while (true) {
            
            try {

                ssize_t n_read = recv(connection->get_socket(), &buffer, buffer_size, 0);
                Logger::debug("Recived " + to_string(n_read) + " bytes on socket #" + to_string(connection->get_socket()));

                if (n_read == 0) {
                    Logger::debug("Client disconnected from socket #" + to_string(connection->get_socket()));
                    close_connection(connection->get_socket());
                    return (false);
                }

                if (n_read == -1) {

                    if (connection->should_retry()) {
                        Logger::debug("EAGAIN/EWOULDBLOCK detected. Retrying...");
                        return (false);
                    }

                    Logger::debug("recv() error, force closing socket #" + to_string(connection->get_socket()));

                }

                if (connection->join_request_buffer(buffer, n_read, this->config_lists)) {

                    HTTPRequest request;

                    connection->parse_request(request);
                    Logger::debug("Request processing done");

                    if (socket_write(connection->get_socket())) {
                        Logger::debug("Response complete");
                        close_connection(connection->get_socket());
                        return true;
                    }

                }

            }

            catch (HTTPRequest::RequestException &e) {

                t_status_code status_code = e.get_status_code();
                
                HTTPResponse response;
                response.set_status(status_code);

                // Handle redirection
                if (status_code >= 300 && status_code < 399 && !e.get_message().empty()) {
                    response.set_header("Location", e.get_message());
                }

                (*connection).ready(response);

                epoll_event event;
                std::memset(&event, 0, sizeof(event));
                socket_write(fd);

                return (false);
            }

        }

    }

    catch (std::exception &e) {
        Logger::error(e.what());
    }

    return (true);

}

bool ConnectionManager::socket_write(int fd) {

    Connection *connection = get_connection_from_fd(fd);

    if (!connection->is_need_to_write()) {
        return (true);
    }

    while (connection->get_response_buffer().length() > 0) {

        connection->update_expiration_time();
        ssize_t n_sended = send(fd, connection->get_response_buffer().c_str(), SOCKET_WRITE_SIZE, MSG_DONTWAIT);

        if (n_sended <= 0) {

            Logger::debug("Sended " + to_string(n_sended) + " bytes");

            if (n_sended == -1) {

                if (connection->should_retry()) {
                    Logger::debug("Buffer is current full or blocking");
                    return (false);
                }

                Logger::debug("Send complete");
                close_connection(fd);

            }

            if (n_sended == 0) {
                Logger::debug("Send complete");
                close_connection(fd);
                return (true);
            }

            Logger::error("Fatal socket error, aborting process");
            close_connection(fd);

        }

        connection->truncate_response_buffer(n_sended);

    }

    Logger::debug("socket_write closing connection");
    close_connection(fd);

    return (true);

}

std::map<int, ServerConfig::ServerConfigData> ConnectionManager::get_server_data() {
    return this->server_data;
}

Connection *ConnectionManager::get_connection_from_fd(int fd) {

    std::map<int, Connection>::iterator iter = this->connections.find(fd);

    if (iter != connections.end()) {
        return &iter->second;
    }

    return (NULL);

}

ServerConfig::ServerConfigData *ConnectionManager::get_server_from_fd(int fd) {

    for (
        std::map<int, ServerConfig::ServerConfigData>::iterator iter = this->server_data.begin();
        iter != this->server_data.end();
        ++iter
    ) {
        if (fd == iter->first) {
            return &iter->second;
        }
    }

    return (NULL);

}

void ConnectionManager::set_epoll_socket(int epoll_fd) {
    epoll_socket = epoll_fd;
}
