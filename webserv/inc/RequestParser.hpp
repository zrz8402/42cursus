#ifndef REQUESTPARSER_HPP
#define REQUESTPARSER_HPP

#include <string>
#include <map>

class RequestParser {
public:
    RequestParser();
    bool parse(const std::string& request_data);

    std::string get_method() const;
    std::string get_path() const;
    std::string get_http_version() const;
    std::map<std::string, std::string> get_headers() const;

private:
    std::string _method;
    std::string _path;
    std::string _http_version;
    std::map<std::string, std::string> _headers;
};

#endif
