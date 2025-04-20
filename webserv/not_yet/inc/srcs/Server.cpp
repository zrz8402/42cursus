#include "Logger.hpp"
#include "Server.hpp"
#include "HTTPRequest.hpp"

Server::Server(ServerConfig &config): configs(config) {
    this->is_running = true;
    signal(SIGPIPE, SIG_IGN);
}

Server::~Server() {}

bool Server::has_socket(int socket) {
    
    for (
        std::vector<int>::iterator iter = this->server_sockets.begin();
        iter != this->server_sockets.end();
        ++iter
    ) {
		if (*iter == socket) {
			return (true);
        }
    }

	return (false);

}

bool Server::setup_sockets(ConnectionManager &manager) {

    int port;
    std::set<int> used_ports;
    
    int n_success = 0;

    for (
        std::vector<ServerConfig::ServerConfigData>::iterator iter = this->configs.get_config_lists().begin();
        iter != this->configs.get_config_lists().end();
        ++iter
    ) {

        port = iter->listen_port;

        if (used_ports.find(port) != used_ports.end()) {
            Logger::warning("Port " + to_string(port) + " has already been binded");
            continue;
        }

        try {

            int fd = socket(AF_INET, SOCK_STREAM, 0);

            if (fd < 0) {
                throw std::runtime_error("Cannot open server socket");
            }

            if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1) {
                close(fd);
                throw std::runtime_error("Failed to set socket to non-blocking mode");
            }

            int opt = 1;

            if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
                Logger::error("Failed to set reuse address for socket");
            }

            sockaddr_in server_address;

            std::memset(&server_address, 0, sizeof(sockaddr_in));
            server_address.sin_family = AF_INET;
            server_address.sin_addr.s_addr = INADDR_ANY;
            server_address.sin_port = htons(iter->listen_port);

            if (bind(fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
                // throw std::runtime_error("Failed to bind to port " + iter->listen_port);
                throw std::runtime_error("Failed to bind to port ");
            }

            if (listen(fd, MAX_CONNECTION) < 0) {
                throw std::runtime_error("Cannot listen to the server");
            }

            this->server_sockets.push_back(fd);
            used_ports.insert(port);
            manager.add_server(fd, *iter);

        }

        catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        n_success++;

    }

    std::map<int, ServerConfig::ServerConfigData> tmp = manager.get_server_data();

    for (
        std::map<int, ServerConfig::ServerConfigData>::iterator iter = tmp.begin();
        iter != tmp.end();
        ++iter
    ) {
        Logger::info("Listening on http://" + iter->second.host + ":" + to_string(iter->second.listen_port));
    }

    return n_success > 0;

}

void Server::start() {

    Logger::info("Starting webserv...");

    ConnectionManager manager;
    setup_sockets(manager);

    int epoll_fd = epoll_create1(0);

    if (epoll_fd == -1) {
        throw std::runtime_error("Cannot create epoll fd");
    }

    manager.set_epoll_socket(epoll_fd);

    struct epoll_event events[CONCURRENT_EVENT_MAX];
    std::memset(events, 0, sizeof(events));

    size_t idx = 0;

	for (std::vector<int>::iterator iter = this->server_sockets.begin(); iter != this->server_sockets.end(); ++iter) {
        
        events[idx].events = EPOLLIN;
        events[idx].data.fd = *iter;
		
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, *iter, &events[idx]) < 0) {
			throw std::runtime_error("Failed to set epoll socket");
        }

		idx++;

    }

    Logger::info("Setup complete. Awaiting connection...");

    HTTPRequest request;
    time_t expired_time = time(NULL) + 10;

    while (true) {

        if (time(NULL) > expired_time) {
            break;
        }

        int n_event_trigger = epoll_wait(epoll_fd, events, CONCURRENT_EVENT_MAX, SOCKET_TIMEOUT_MS);

        // timeout event
        if (n_event_trigger == 0) {
            continue;
        }

        // error
        if (n_event_trigger == -1) {
            throw std::runtime_error("Socket epoll_wait error");
        }

        for (int idx = 0; idx < n_event_trigger; idx++) {

            int active_fd = events[idx].data.fd;
            
            Logger::debug("epoll event triggered at fd #" + to_string(active_fd));
            ServerConfig::ServerConfigData *server_data = manager.get_server_from_fd(active_fd);

            if (has_socket(active_fd)) {

                // On error (EPOLLRDHUP/EPOLLHUP/EPOLLERR)
                if (
                    (events[idx].events & EPOLLRDHUP)
                    || (events[idx].events & EPOLLHUP)
                    || (events[idx].events & EPOLLERR)
                ) {

                    Logger::debug("Failed to listen on socket #" + to_string(active_fd));

                    int error_code;
                    socklen_t error_length = sizeof(error_code);

                    getsockopt(active_fd, SOL_SOCKET, SO_ERROR, &error_code, &error_length);
                    // Logger::error(error_length);

                    close(active_fd);
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, active_fd, NULL);

                    continue;

                }

                // On incoming request (EPOLLIN)
                if (events[idx].events & EPOLLIN) {

                    if (!server_data) {
                        throw std::runtime_error("Unable to load server on target socket");
                    }

                    struct sockaddr_in client_address;
                    socklen_t address_size = sizeof(client_address);

                    int client_socket = accept(active_fd, (struct sockaddr *) &client_address, &address_size);

                    if (client_socket < 0) {
                        throw std::runtime_error("Failed to accept incoming client socket");
                    }

                    manager.open_connection(client_socket, *server_data);
                    continue;

                }

            }

        }

        this->manager.remove_expired_connections();

    }

    close(epoll_fd);

}
