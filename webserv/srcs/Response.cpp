#include "Response.hpp"
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <iostream>

Response::Response(
    const Request& request,
    const ServerConfig::ServerConfigData& server,
    const ServerConfig::LocationConfig& location
) : _request(request), _server(server), _location(location), _status_code(200) {}

/*
Purpose: This function builds the full HTTP response.
1.It first constructs the full_path by combining the root directory from _location
with the requested path from the Request.
2.It checks if the file exists:
If it doesn’t, it sets the status code to 404 (Not Found) and generates an error body.
If it does, it sets the status code to 200 (OK) and reads the file contents into the response body.
3.It sets the Content-Length header based on the size of the body
and adds the Connection header with the value close.
4.It then combines the status line, headers, and body into a single string,
which is returned as the full HTTP response.
*/
std::string Response::build_response() {
    std::string full_path = _location.root + _request.get_path();

    // Check if file exists and handle error if necessary
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

    // Set headers
    std::ostringstream oss;
    oss << _body.size();
    _headers["Content-Length"] = oss.str();
    _headers["Connection"] = "close";

    return build_status_line() + build_headers() + "\r\n" + _body;
}

/*
Purpose: This function generates the HTTP status line (e.g., HTTP/1.1 200 OK).
1.It uses a std::ostringstream to format the status line.
2.The status code and message are inserted into the stream,
and the result is returned as a string.
*/
std::string Response::build_status_line() {
    std::ostringstream oss;
    oss << "HTTP/1.1 " << _status_code << " " << _status_message << "\r\n";
    return oss.str();
}

std::string Response::build_headers() {
    std::string out;
    for (std::map<std::string, std::string>::iterator it = _headers.begin(); it != _headers.end(); ++it) {
        out += it->first + ": " + it->second + "\r\n";
    }
    return out;
}

/*
•Purpose: This function checks if a file exists and is a regular file.
1.It uses the stat function to obtain file information.
2.It checks if the file exists (stat returns 0) 
and if it is a regular file (S_ISREG).
*/
bool Response::file_exists(const std::string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0 && S_ISREG(buffer.st_mode));
}

std::string Response::get_file_contents(const std::string& path) {
    std::ifstream file(path.c_str());
    if (!file) {
        std::cerr << "Failed to open file: " << path << std::endl;
        return "";
    }

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

/*
•Purpose: This function generates the body for an error response (e.g., for 404 or 500).
1.It first checks if the server configuration includes a custom error page for the given status code.
2.If a custom error page exists and the file is accessible, it returns the contents of that file.
3.If not, it generates a simple HTML error page with the status code and message (e.g., <h1>404 Not Found</h1>).
*/
std::string Response::build_error_body(int status) {
    std::map<t_status_code, std::string>::const_iterator it = _server.error_pages.find(static_cast<t_status_code>(status));
    if (it != _server.error_pages.end() && file_exists(it->second)) {
        return get_file_contents(it->second);
    }
    std::ostringstream oss;
    oss << "<html><body><h1>" << status << " " << get_status_message(status) << "</h1></body></html>";
    return oss.str();
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
