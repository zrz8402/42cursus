#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <map>
#include "Request.hpp"
#include "ServerConfig.hpp"

class Response {
public:
    Response(
        const Request& request,
        const ServerConfig::ServerConfigData& server,
        const ServerConfig::LocationConfig& location
    );

    std::string build_response();

private:
    const Request& _request;
    const ServerConfig::ServerConfigData& _server;
    const ServerConfig::LocationConfig& _location;

    int _status_code;
    std::string _status_message;
    std::string _body;
    std::map<std::string, std::string> _headers;

    std::string get_file_contents(const std::string& path);
    bool file_exists(const std::string& path);
    std::string get_status_message(int code);
    std::string get_content_type(const std::string& path);
    std::string build_status_line();
    std::string build_headers();
    std::string build_error_body(int status);
};

#endif
