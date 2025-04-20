#include "Request.hpp"
#include <sstream>
#include <algorithm>

Request::Request() : _state(START_LINE), _content_length(0) {}

bool Request::parse(const std::string& buffer) {
    _raw_request += buffer;
    std::istringstream stream(_raw_request);
    std::string line;

    while (std::getline(stream, line)) {
        if (_state == START_LINE) {
            if (!parse_start_line(line)) {
                _state = ERROR;
                return false;
            }
            _state = HEADERS;
        } else if (_state == HEADERS) {
            if (line == "\r" || line.empty()) {
                if (_headers.count("Content-Length")) {
                    _content_length = std::atoi(_headers["Content-Length"].c_str());
                    _state = BODY;
                } else {
                    _state = COMPLETE;
                    return true;
                }
            } else {
                parse_header_line(line);
            }
        } else if (_state == BODY) {
            parse_body(stream.str().substr(stream.tellg()));
            if (_body.size() >= _content_length) {
                _state = COMPLETE;
                return true;
            }
            break;
        }
    }

    return _state == COMPLETE;
}
bool Request::is_complete() const {
    return _state == COMPLETE;
}

bool Request::has_error() const {
    return _state == ERROR;
}

bool Request::parse_start_line(const std::string& line) {
    std::istringstream iss(line);
    if (!(iss >> _method >> _path >> _http_version)) {
        return false;
    }

    if (_http_version.substr(0, 5) != "HTTP/")
        return false;

    return true;
}

void Request::parse_header_line(const std::string& line) {
    size_t colon = line.find(':');
    if (colon != std::string::npos) {
        std::string key = line.substr(0, colon);
        std::string value = line.substr(colon + 1);
        key.erase(key.find_last_not_of(" \t\r") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t\r") + 1);

        _headers[key] = value;

        if (key == "Host") {
            _host = value;
            size_t colon_pos = _host.find(':');
            if (colon_pos != std::string::npos) {
                _port = std::atoi(_host.substr(colon_pos + 1).c_str());
                _host = _host.substr(0, colon_pos);
            } else {
                _port = 80;
            }
        }
    }
}

void Request::parse_body(const std::string& chunk) {
    _body += chunk;
}

const std::string& Request::get_method() const { return _method; }
const std::string& Request::get_path() const { return _path; }
const std::string& Request::get_http_version() const { return _http_version; }
const std::map<std::string, std::string>& Request::get_headers() const { return _headers; }
const std::string& Request::get_body() const { return _body; }
const std::string& Request::get_host() const { return _host; }
int Request::get_port() const { return _port; }
