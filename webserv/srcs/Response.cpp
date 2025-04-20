#include "Response.hpp"
#include <fstream>
#include <sstream>
#include <sys/stat.h>

Response::Response(
    const Request& request,
    const ServerConfig::ServerConfigData& server,
    const ServerConfig::LocationConfig& location
) : _request(request), _server(server), _location(location), _status_code(200) {}

std::string Response::build_response() {
    std::string full_path = _location.root + _request.get_path();

    if (!file_exists(full_path)) {
        _status_code = 404;
        _status_message = get_status_message(_status_code);
        _body = build_error_body(_status_code);
        _headers["Content-Type"] = "text/html";
    } else {
        _status_code = 200;
        _status_message = get_status_message(_status_code);
        _body = get_file_contents(full_path);
        _headers["Content-Type"] = get_content_type(full_path);
    }

    _headers["Content-Length"] = std::to_string(_body.size());
    _headers["Connection"] = "close";

    return build_status_line() + build_headers() + "\r\n" + _body;
}

std::string Response::build_status_line() {
    return "HTTP/1.1 " + std::to_string(_status_code) + " " + _status_message + "\r\n";
}

std::string Response::build_headers() {
    std::string out;
    for (std::map<std::string, std::string>::iterator it = _headers.begin(); it != _headers.end(); ++it) {
        out += it->first + ": " + it->second + "\r\n";
    }
    return out;
}

bool Response::file_exists(const std::string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0 && S_ISREG(buffer.st_mode));
}

std::string Response::get_file_contents(const std::string& path) {
    std::ifstream file(path.c_str());
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

std::string Response::get_status_message(int code) {
    switch (code) {
        case 200: return "OK";
        case 404: return "Not Found";
        case 403: return "Forbidden";
        case 500: return "Internal Server Error";
        default: return "Unknown";
    }
}

std::string Response::build_error_body(int status) {
    std::map<int, std::string>::const_iterator it = _server.error_pages.find(status);
    if (it != _server.error_pages.end() && file_exists(it->second)) {
        return get_file_contents(it->second);
    }
    return "<html><body><h1>" + std::to_string(status) + " " + get_status_message(status) + "</h1></body></html>";
}

std::string Response::get_content_type(const std::string& path) {
    size_t dot = path.find_last_of('.');
    if (dot == std::string::npos) return "text/plain";

    std::string ext = path.substr(dot);
    if (ext == ".html") return "text/html";
    if (ext == ".css") return "text/css";
    if (ext == ".js") return "application/javascript";
    if (ext == ".png") return "image/png";
    if (ext == ".jpg" || ext == ".jpeg") return "image/jpeg";
    if (ext == ".gif") return "image/gif";
    return "application/octet-stream";
}
#include "Response.hpp"
#include <fstream>
#include <sstream>
#include <sys/stat.h>

Response::Response(
    const Request& request,
    const ServerConfig::ServerConfigData& server,
    const ServerConfig::LocationConfig& location
) : _request(request), _server(server), _location(location), _status_code(200) {}

std::string Response::build_response() {
    // Handle Redirection
    if (_location.return_code != 0 && !_location.return_url.empty()) {
        _status_code = _location.return_code;
        _status_message = get_status_message(_status_code);
        _headers["Location"] = _location.return_url;
        _headers["Content-Length"] = "0";
        _headers["Connection"] = "close";
        return build_status_line() + build_headers() + "\r\n";
    }

    // Static file serving
    std::string full_path = _location.root + _request.get_path();

    if (!file_exists(full_path)) {
        _status_code = 404;
        _status_message = get_status_message(_status_code);
        _body = build_error_body(_status_code);
        _headers["Content-Type"] = "text/html";
    } else {
        _status_code = 200;
        _status_message = get_status_message(_status_code);
        _body = get_file_contents(full_path);
        _headers["Content-Type"] = get_content_type(full_path);
    }

    _headers["Content-Length"] = std::to_string(_body.size());
    _headers["Connection"] = "close";

    return build_status_line() + build_headers() + "\r\n" + _body;
}

std::string Response::build_status_line() {
    return "HTTP/1.1 " + std::to_string(_status_code) + " " + _status_message + "\r\n";
}

std::string Response::build_headers() {
    std::string out;
    for (std::map<std::string, std::string>::iterator it = _headers.begin(); it != _headers.end(); ++it) {
        out += it->first + ": " + it->second + "\r\n";
    }
    return out;
}

bool Response::file_exists(const std::string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0 && S_ISREG(buffer.st_mode));
}

std::string Response::get_file_contents(const std::string& path) {
    std::ifstream file(path.c_str());
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

std::string Response::get_status_message(int code) {
    switch (code) {
        case 200: return "OK";
        case 301: return "Moved Permanently";
        case 302: return "Found";
        case 307: return "Temporary Redirect";
        case 308: return "Permanent Redirect";
        case 403: return "Forbidden";
        case 404: return "Not Found";
        case 500: return "Internal Server Error";
        default: return "Unknown";
    }
}

std::string Response::build_error_body(int status) {
    std::map<int, std::string>::const_iterator it = _server.error_pages.find(status);
    if (it != _server.error_pages.end() && file_exists(it->second)) {
        return get_file_contents(it->second);
    }
    return "<html><body><h1>" + std::to_string(status) + " " + get_status_message(status) + "</h1></body></html>";
}

std::string Response::get_content_type(const std::string& path) {
    size_t dot = path.find_last_of('.');
    if (dot == std::string::npos) return "text/plain";

    std::string ext = path.substr(dot);
    if (ext == ".html") return "text/html";
    if (ext == ".css") return "text/css";
    if (ext == ".js") return "application/javascript";
    if (ext == ".png") return "image/png";
    if (ext == ".jpg" || ext == ".jpeg") return "image/jpeg";
    if (ext == ".gif") return "image/gif";
    return "application/octet-stream";
}