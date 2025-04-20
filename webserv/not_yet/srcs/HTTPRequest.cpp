#include "HTTPRequest.hpp"

HTTPRequest::HTTPRequest() {
    this->content_length = 0;
}

HTTPRequest::~HTTPRequest() {}

bool HTTPRequest::parse_request_line(const std::string &line) {

    std::istringstream line_stream(line);
    
    if (!(line_stream >> this->method >> this->path >> this->version)) {
        return false;
    }

    if (this->version.find("HTTP") == std::string::npos){
        return false;
    }
    
    size_t query_start = this->path.find('?');
    
    if (query_start != std::string::npos) {
        this->query = path.substr(query_start + 1);
        this->path = path.substr(0, query_start);
    }
    
    return true;
    
}

bool HTTPRequest::parse_header_chunk(const std::string &header_chunk) {

    std::string line;
    std::istringstream header_stream(header_chunk);

    if (!std::getline(header_stream, line)) {
        Logger::error("Failed to read a request line");
        return false;
    }

    if (line[line.length() - 1] == '\r') {
        line.erase(line.length() - 1);
    }

    if (!parse_request_line(line)) {
        Logger::error("Failed to read request at line: " + line);
        return false;
    }

    std::map<std::string, std::string>::iterator content_length_iter = this->headers.find("Content-Length");
    if (content_length_iter != this->headers.end()) {
        this->content_length = std::atoi(content_length_iter->second.c_str());
    }

    std::map<std::string, std::string>::iterator content_type_iter = this->headers.find("Content-Type");
    if (content_type_iter != this->headers.end()) {
        this->content_type = content_type_iter->second;
    }

    std::map<std::string, std::string>::iterator cookie_iterator = this->headers.find("Cookie");
    if (cookie_iterator != this->headers.end()) {
        this->cookie = cookie_iterator->second;
    }

    return true;

}

bool HTTPRequest::parse_header_line(const std::string &line) {

    size_t delimiter_pos = line.find(':');

    if (delimiter_pos == std::string::npos) {
        return false;
    }

    std::string key = line.substr(0, delimiter_pos);
    std::string value = line.substr(delimiter_pos + 1);

    value = ServerConfigUtils::trim(value);
    this->headers[key] = value;

    return true;

}

bool HTTPRequest::parse(const std::string &request, std::vector<char> &raw_body) {
    this->raw_body = raw_body;
    return parse_header_chunk(request);
}

bool HTTPRequest::parse(int fd) {
    
    char buffer[4096];
    
    ssize_t n_read;
    std::string request;

    bool is_header_done = false;
    size_t n_read_total = 0;
    size_t expected_content_length = 0;

    while ((n_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {

        buffer[n_read] = '\0';
        request.append(buffer, n_read);

        size_t header_end_pos = request.find("\r\n\r\n");

        if (header_end_pos != std::string::npos) {

            std::string headers = request.substr(0, header_end_pos);

            if (!parse_header_chunk(headers)) {
                Logger::error("Failed to parse request headers");
                return false;
            }

            std::map<std::string, std::string>::iterator content_length_iter = this->headers.find("Content-Length");

            if (content_length_iter != this->headers.end()) {
                expected_content_length = std::atoi(content_length_iter->second.c_str());
                Logger::debug("Expected content length " + to_string(expected_content_length));
            }

            this->body = request.substr(header_end_pos + 4);
            n_read_total = this->body.length();
            Logger::debug("Initial body read: " + to_string(n_read_total) + " bytes");

            if (expected_content_length == 0 || n_read_total >= expected_content_length) {
                Logger::debug("All content recived");
                return is_valid_request();
            }

            is_header_done = true;
            break;

        }

    }

    if (n_read < 0 && errno != EAGAIN && errno != EWOULDBLOCK) {
        Logger::error("Failed to read from socket: " + std::string(strerror(errno)));
    }

    if (is_header_done && expected_content_length > 0) {

        Logger::debug("Reading body...");

        while (n_read_total < expected_content_length) {

            n_read = read(fd, buffer, std::min(sizeof(buffer) - 1, expected_content_length - n_read_total));

            if (n_read <= 0) {

                if (n_read < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
                    continue;
                }

                Logger::error("Failed to read request body: " + std::string(strerror(errno)));
                return (false);

            }

            this->body.append(buffer, n_read);
            n_read_total += n_read;

            Logger::debug("Read " + to_string(n_read_total) + " of " + to_string(expected_content_length) + " bytes");

        }

    }

    Logger::debug("Request parsing done");
    return is_valid_request();

}

bool HTTPRequest::set_header(std::string key, std::string value, bool overwrite) {

    std::map<std::string, std::string>::const_iterator pos = this->headers.find(key);

    if (pos != this->headers.end() && !overwrite) {
        return false;
    }

    else if (pos != this->headers.end() && overwrite) {

        while (pos != this->headers.end()) {
            key += " ";
            pos = this->headers.find(key);
        }

        this->headers[key] = value;
        return true;

    }

    else {
        this->headers[key] = value;
        return true;
    }

}

bool HTTPRequest::parse_header(ServerConfig::ServerConfigData config, std::string request) {

    std::string line;
    std::istringstream request_stream(request);

    if (std::getline(request_stream, line)) {

        std::istringstream line_stream;
        std::string method, raw_path, version;

        if (!(line_stream >> method >> raw_path >> version)) {
            throw RequestException(BAD_REQUEST);
        }

        {
            
            // Catching path traversal url injection
            size_t parent_path_pos = raw_path.find("..");

            if (parent_path_pos != std::string::npos) {
                throw RequestException(BAD_REQUEST);
            }

        }

        this->method = method;
        this->path = raw_path;

        size_t query_pos = raw_path.find('?');

        if (query_pos != std::string::npos) {

            this->path = raw_path.substr(0, query_pos);
            this->query = raw_path.substr(query_pos + 1);
            
            std::string key_value_str;
            std::istringstream query_stream(this->query);

            while (std::getline(query_stream, key_value_str, '&')) {

                size_t equal_pos = key_value_str.find('=');

                if (equal_pos != std::string::npos) {
                    this->query_map[key_value_str.substr(0, equal_pos)] = key_value_str.substr(equal_pos + 1);
                }

                else {
                    this->query_map[key_value_str] = "";
                }

            }

        }

        else {
            this->path = raw_path;
        }

    }

    while (std::getline(request_stream, line) && line != "\r") {

        size_t colon_pos = line.find(':');

        if (colon_pos != std::string::npos) {
            std::string key = line.substr(0, colon_pos);
            std::string value = ServerConfigUtils::trim(line.substr(colon_pos + 1));
            this->set_header(key, value, false);
        }

    }

    if (this->headers.find("Content-Length") != headers.end()) {

        size_t content_length_value = std::atoi(this->headers["Content-Length"].c_str());

        if (content_length_value > config.client_max_body_size) {
            throw RequestException(TOO_LARGE);
        }

        this->content_length = content_length_value;

        std::string body_str(this->content_length, '\0');
        request_stream.read(&body_str[0], this->content_length);

        this->body = body_str;

    }

}

bool HTTPRequest::is_valid_request() {

    if (this->method.empty() || this->path.empty() || this->version.empty()) {
        return false;
    }

    if (this->version != "HTTP/1.0" && this->version != "HTTP/1.1") {
        return false;
    }

    return true;

}

const std::string &HTTPRequest::get_method() const {
    return this->method;
}

const std::string &HTTPRequest::get_path() const {
    return this->path;
}

const std::string &HTTPRequest::get_query() const {
    return this->query;
}

const std::string &HTTPRequest::get_version() const {
    return this->version;
}

const std::string &HTTPRequest::get_body() const {
    return this->body;
}

const std::string &HTTPRequest::get_content_type() const {
    return this->content_type;
}

const std::string &HTTPRequest::get_cookie() const {
    return this->cookie;
}

const std::vector<char> &HTTPRequest::get_raw_body() const {
    return this->raw_body;
}

const std::map<std::string, std::string> &HTTPRequest::get_headers() const {
    return this->headers;
}

std::string HTTPRequest::get_header_value(const std::string &key) const {

    std::string result;

    try {
        result = this->headers.at(key);
    }

    catch (std::exception &e) {
        result = "";
    }

    return result;

}

size_t HTTPRequest::get_content_length() const {
    return this->content_length;
}

HTTPRequest::RequestException::RequestException() {
    this->status_code = BAD_REQUEST;
    this->message = this->get_message_from_status();
}

HTTPRequest::RequestException::RequestException(const RequestException &base) {
    this->status_code = base.status_code;
    this->message = base.message;
}

HTTPRequest::RequestException::RequestException(t_status_code status_code) {
    this->status_code = status_code;
    this->message = this->get_message_from_status();
}

HTTPRequest::RequestException::RequestException(t_status_code status_code, const std::string &message) {
    this->status_code = status_code;
    this->message = message;
}

HTTPRequest::RequestException &HTTPRequest::RequestException::operator=(const RequestException &rhs) {
    this->status_code = rhs.status_code;
    this->message = rhs.message;
    return *this;
}

HTTPRequest::RequestException::~RequestException() throw () {}

const char *HTTPRequest::RequestException::what() const throw () {
    return this->message.c_str();
}

t_status_code HTTPRequest::RequestException::get_status_code() const {
    return this->status_code;
}

std::string HTTPRequest::RequestException::get_message() const {
    return this->message;
}

std::string HTTPRequest::RequestException::get_message_from_status() const {
    return HTTPResponse::get_message_from_status(this->status_code);
}
