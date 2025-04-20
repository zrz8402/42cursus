#ifndef RESPONSEBUILDER_HPP
#define RESPONSEBUILDER_HPP

#include <string>
#include <map>
#include "RequestParser.hpp"

class ResponseBuilder {
public:
    ResponseBuilder(const RequestParser& request);

    std::string build_response();

private:
    std::string build_status_line();
    std::string build_headers();
    std::string build_body();
    std::string get_file_contents(const std::string& path);

    const RequestParser& _request;
    std::map<std::string, std::string> _headers;
    std::string _body;
    int _status_code;
    std::string _status_message;
};

#endif
