#include "Connection.hpp"

Connection::Connection(int fd, ServerConfig::ServerConfigData &server_config): config(server_config) {

    this->fd = fd;
    
    this->is_ready = false;
    this->body_length = 0;
    this->expires_time = time(NULL) + CONNECTION_TIMEOUT;
    this->route_configs = this->config.locations;

    set_nonblock_mode();
    raw_post_body.clear();
}

Connection::~Connection() {}

void Connection::set_nonblock_mode() {

    int flags = fcntl(this->fd, F_GETFL, 0);

    if (flags >= 0) {
        if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
            throw std::runtime_error("Cannot set target socket to non-blocking mode.");
        }
    }

}

Connection &Connection::operator=(const Connection &rhs) {
    
    this->fd = rhs.fd;
	this->expires_time = rhs.expires_time;
	this->config = rhs.config;
	this->is_ready = rhs.is_ready; 
	
    this->request_buffer = rhs.request_buffer;
	this->response_buffer = rhs.response_buffer;
    
    this->raw_post_body = rhs.raw_post_body;
	this->raw_post_body.clear();
	
	this->body_length = rhs.body_length;
	this->content_length = rhs.content_length;

	this->epoll_socket = rhs.epoll_socket; 

	return (*this);

}

int Connection::get_socket() {
    return this->fd;
}

bool Connection::get_header_status() {
    return this->is_header_done;
}

bool Connection::get_request_status() {
    return this->is_request_done;
}

std::string Connection::get_response_buffer() {
    return this->response_buffer;
}

bool Connection::should_retry() {

    int errno_value = 0;
    socklen_t errno_size = sizeof(errno_value);

    if (getsockopt(this->fd, SOL_SOCKET, SO_ERROR, &errno_value, &errno_size) == 0) {
        return (errno_value == EAGAIN || errno_value == EWOULDBLOCK);
    }

    return false;

}

bool Connection::join_request_buffer(char *buffer, size_t length, std::vector<ServerConfig::ServerConfigData> servers) {

    bool is_splitted = false;

    if (!this->is_header_done) {

        if (this->request_buffer.length() == 0) {

            std::string line;
            std::istringstream stream(std::string(buffer, length));

            std::getline(stream, line);

            std::string method, path, version;
            std::istringstream line_stream(line);

            if (!(line_stream >> method >> path >> version)) {
                throw HTTPRequest::RequestException(BAD_REQUEST);
            }

            if (version.find("HTTP/1.") == std::string::npos) {
                throw HTTPRequest::RequestException(BAD_REQUEST);
            }

            Logger::request("[" + method + "] " + path);

        }

        request_buffer += std::string(buffer, length);

        size_t crlf_pos = request_buffer.find("\r\n\r\n");

        if (crlf_pos == std::string::npos) {
            return false;
        }

        else {
            this->is_header_done = true;
        }

        std::string line;
        std::istringstream request_stream(request_buffer);

        size_t request_content_length = 0;

        while (std::getline(request_stream, line) && line != "\r") {

            if (line.find("Content-Length:") == 0) {

                std::istringstream line_stream(line);

                if (!(line_stream >> request_content_length)) {
                    throw HTTPRequest::RequestException(BAD_REQUEST);
                }

                this->content_length = request_content_length;

            }

            if (line.find("Content-Type:") == 0) {

                std::istringstream line_stream(line.substr(15));

                if (!(line_stream >> request_content_length)) {

                    size_t boundary_pos = line.find("boundary=");

                    if (boundary_pos != std::string::npos) {
                        this->boundary = line.substr(boundary_pos + 9);
                    }

                }

            }

            if (line.find("Host:") == 0) {

                std::string hostname;
                std::istringstream line_stream(line.substr(5));

                if (line_stream >> hostname) {

                    Logger::debug("Hostname: " + hostname);

                    for (
                        std::vector<ServerConfig::ServerConfigData>::iterator iter = servers.begin();
                        iter != servers.end();
                        ++iter
                    ) {

                        std::string full_hostname = iter->host + ":" + to_string(iter->listen_port);

                        if (full_hostname.find(hostname) != std::string::npos) {
                            Logger::debug("Overwriting server host to: " + iter->host);
                            this->config = *iter;
                        }

                    }

                }

            }

        }

        if (this->content_length <= 0) {
            this->content_length = 0;
        }

        if (this->content_length <= this->raw_post_body.size()) {
            this->is_request_done = true;
            return true;
        }

        std::string tmp = request_buffer.substr(crlf_pos + 4, request_buffer.length());

        for (size_t idx = 0; idx < tmp.length(); idx++) {
            this->raw_post_body.push_back(tmp[idx]);
        }

        is_splitted = true;
        this->request_buffer = this->request_buffer.substr(0, crlf_pos);

    }

    if (this->is_header_done && !is_splitted) {
        for (size_t idx = 0; idx < length; idx++) {
            char c = buffer[idx];
            this->raw_post_body.push_back(c);
        }
    }

    if (this->content_length == 0) {
        this->is_request_done = true;
        return (true);
    }

    else if (this->content_length <= this->raw_post_body.size()) {
        this->is_request_done = true;
        return (true);
    }

    return (false);

}


// TODO
bool Connection::parse_request(HTTPRequest &request) {

    Logger::debug("Processing request...");

    request.parse_header(this->config, this->request_buffer);
    ServerConfig::LocationConfig *target_route = Router::find_route_from_path(this->route_configs, request.get_path());

    HTTPResponse response;

    std::string path = request.get_path();
    std::string method = request.get_method();

    if (path.find("..") != std::string::npos) {
        throw HTTPRequest::RequestException(BAD_REQUEST);
    }

    if (target_route->redirect_status != 0) {

        t_status_code status_code = target_route->redirect_status;

        if (status_code >= 300 && status_code <= 399) {
            if (!target_route->redirect.empty()) {
                throw HTTPRequest::RequestException(status_code, target_route->redirect);
            }
        }

        throw HTTPRequest::RequestException(status_code, "");
    
    }

    std::vector<std::string> allowed_methods = target_route->allowed_methods;

    if (std::find(allowed_methods.begin(), allowed_methods.end(), method) == allowed_methods.end()) {
        throw HTTPRequest::RequestException(METHOD_NOT_ALLOWED);
    }

    std::string tmp = request.get_header_value("Content-Length");

    if (request.get_method() == "POST" && tmp.empty()) {
        throw HTTPRequest::RequestException(LENGTH_REQUIRED);
    }

    size_t max_content_size = target_route->max_body_size;

    if (max_content_size == 0) {
        max_content_size = DEFAULT_MAX_BODY_SIZE;
    }

    if (!tmp.empty() && static_cast<size_t>(std::atol(tmp.c_str())) > max_content_size) {
        throw HTTPRequest::RequestException(TOO_LARGE);
    }

    // TODO: File handler + CGI
    // std::string local_path = "";

}

bool Connection::ready(HTTPResponse &response, bool send) {

    this->is_ready = true;
    this->request_buffer = "";

}

void Connection::clear() {

    this->raw_post_body.clear();

    this->is_ready = false;
    this->is_header_done = false;
    this->is_request_done = false;

    this->response_buffer = "";

    this->body_length = 0;
    this->content_length = 0;

}

void Connection::update_expiration_time() {

    char buffer[24];
    struct tm time_info;

    this->expires_time = time(NULL) + SOCKET_TIMEOUT_S;

    localtime_r(&this->expires_time, &time_info);
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S] ", &time_info);

}

bool Connection::is_need_to_write() {
    return (!this->response_buffer.empty());
}

bool Connection::is_connection_expired(time_t current_timestamp) {
    return this->expires_time < current_timestamp;
}

bool Connection::set_expires_time(time_t current_timestamp) {

    char buffer[24];
    this->expires_time = current_timestamp + CONNECTION_TIMEOUT;

    struct tm time_info;
    localtime_r(&this->expires_time, &time_info);
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S] ", &time_info);

    return true;

}

ssize_t Connection::truncate_response_buffer(ssize_t n_sended) {

    n_sended = (n_sended < this->response_buffer.length()) ? n_sended : response_buffer.length();
    this->response_buffer = this->response_buffer.substr(n_sended);

    return this->response_buffer.size();

}
