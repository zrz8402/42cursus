#include "Request.hpp"
#include <sstream>
#include <algorithm>

Request::Request() : _state(START_LINE), _content_length(0) {}

bool Request::parse(const std::string& buffer) {
    _raw_request += buffer;

    std::istringstream stream(_raw_request);
    std::string line;

    while (std::getline(stream, line)) {
        // Remove '\r' if present
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        if (_state == START_LINE) {
            if (!parse_start_line(line)) {
                _state = ERROR;
                return false;
            }
            _state = HEADERS;
        } else if (_state == HEADERS) {
            if (line.empty()) {
                if (_headers.count("Content-Length")) {
                    _content_length = std::stoi(_headers["Content-Length"]);
                    _state = BODY;
                } else {
                    _state = COMPLETE;
                    return true;
                }
            } else {
                parse_header_line(line);
            }
        }
    }

    if (_state == BODY) {
        size_t header_end = _raw_request.find("\r\n\r\n");
        if (header_end != std::string::npos) {
            std::string body_part = _raw_request.substr(header_end + 4);
            parse_body(body_part);
            if (_body.size() >= _content_length) {
                _state = COMPLETE;
                return true;
            }
        }
    }

    return _state == COMPLETE;
}

bool Request::parse_start_line(const std::string& line) {
    std::istringstream iss(line);
    if (!(iss >> _method >> _path >> _http_version)) {
        return false;
    }
    return true;
}

void Request::parse_header_line(const std::string& line) {
    size_t sep = line.find(':');
    if (sep != std::string::npos) {
        std::string key = line.substr(0, sep);
        std::string value = line.substr(sep + 1);
        key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
        value.erase(0, value.find_first_not_of(" \t"));
        _headers[key] = value;
    }
}

void Request::parse_body(const std::string& chunk) {
    _body += chunk;
}

bool Request::is_complete() const {
    return _state == COMPLETE;
}

bool Request::has_error() const {
    return _state == ERROR;
}

const std::string& Request::get_method() const { return _method; }
const std::string& Request::get_path() const { return _path; }
const std::string& Request::get_http_version() const { return _http_version; }
const std::map<std::string, std::string>& Request::get_headers() const { return _headers; }
const std::string& Request::get_body() const { return _body; }