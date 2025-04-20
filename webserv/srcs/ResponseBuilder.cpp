#include "ResponseBuilder.hpp"
#include <fstream>
#include <sstream>

ResponseBuilder::ResponseBuilder(const RequestParser& request) : _request(request), _status_code(200) {}

std::string ResponseBuilder::build_response() {
    _status_code = 200; // Default to OK
    _status_message = "OK";

    std::string path = "." + _request.get_path(); // Just for simplicity, serving files from current directory
    _body = get_file_contents(path);
    
    if (_body.empty()) {
        _status_code = 404;
        _status_message = "Not Found";
        _body = "<h1>404 Not Found</h1>";
    }

    return build_status_line() + build_headers() + "\r\n" + _body;
}

std::string ResponseBuilder::build_status_line() {
    std::ostringstream status_line;
    status_line << "HTTP/1.1 " << _status_code << " " << _status_message << "\r\n";
    return status_line.str();
}

std::string ResponseBuilder::build_headers() {
    std::ostringstream headers;
    headers << "Content-Length: " << _body.length() << "\r\n";
    headers << "Content-Type: text/html\r\n";
    return headers.str();
}

std::string ResponseBuilder::get_file_contents(const std::string& path) {
    std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);
    std::stringstream buffer;
    if (file) {
        buffer << file.rdbuf();
    }
    return buffer.str();
}