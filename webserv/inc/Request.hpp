#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>

class Request {
public:
    enum State {
        START_LINE,
        HEADERS,
        BODY,
        COMPLETE,
        ERROR
    };

    Request();

    bool parse(const std::string& buffer);
    bool is_complete() const;
    bool has_error() const;

    const std::string& get_method() const;
    const std::string& get_path() const;
    const std::string& get_http_version() const;
    const std::map<std::string, std::string>& get_headers() const;
    const std::string& get_body() const;
    const std::string& get_host() const;
    int get_port() const;

private:
    bool parse_start_line(const std::string& line);
    void parse_header_line(const std::string& line);
    void parse_body(const std::string& chunk);
    void trim(std::string& str) const;

    State _state;
    std::string _raw_request;
    std::string _method;
    std::string _path;
    std::string _http_version;
    std::string _host;
    int _port;
    std::map<std::string, std::string> _headers;
    std::string _body;
    int _content_length;
};

#endif
