#include "RequestParser.hpp"
#include <sstream>

RequestParser::RequestParser() {}

bool RequestParser::parse(const std::string& request_data) {
    std::istringstream stream(request_data);
    std::string line;
    bool is_first_line = true;

    while (std::getline(stream, line)) {
        if (is_first_line) {
            std::istringstream line_stream(line);
            if (!(line_stream >> _method >> _path >> _http_version)) {
                return false;
            }
            is_first_line = false;
        } else if (!line.empty()) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string header_name = line.substr(0, pos);
                std::string header_value = line.substr(pos + 1);
                _headers[header_name] = header_value;
            }
        }
    }

    return true;
}

std::string RequestParser::get_method() const {
    return _method;
}

std::string RequestParser::get_path() const {
    return _path;
}

std::string RequestParser::get_http_version() const {
    return _http_version;
}

std::map<std::string, std::string> RequestParser::get_headers() const {
    return _headers;
}