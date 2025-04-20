#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <string.h>

#include "constants.hpp"
#include "ServerConfig.hpp"
#include "Logger.hpp"
#include "ServerConfigUtils.hpp"
#include "HTTPResponse.hpp"

class HTTPRequest {

    private:

        std::string method;
        std::string path;
        std::string query;
        std::string version;
        std::string body;
        std::string content_type;
        std::string cookie;

        size_t content_length;

        std::vector<char> raw_body;
        std::map<std::string, std::string> headers;
        std::map<std::string, std::string> query_map;

        bool is_valid_request();
        bool parse_request_line(const std::string &line);
        bool parse_header_line(const std::string &line);
        bool parse_header_chunk(const std::string &header_chunk);
        
    public:

        HTTPRequest();
        ~HTTPRequest();

        bool parse(int fd);
        bool parse(const std::string &request, std::vector<char> &raw_body);

        bool set_header(std::string key, std::string value, bool overwrite);
        bool parse_header(ServerConfig::ServerConfigData config, std::string request);

        const std::string &get_method() const;
        const std::string &get_path() const;
        const std::string &get_query() const;
        const std::string &get_version() const;
        const std::string &get_body() const;
        const std::string &get_content_type() const;
        const std::string &get_cookie() const;

        const std::vector<char> &get_raw_body() const;
        const std::map<std::string, std::string> &get_headers() const;

        size_t get_content_length() const;
        std::string get_header_value(const std::string &key) const;

        class RequestException: public std::exception {
            
            private:
                std::string	message;
                t_status_code status_code;

            public:

                RequestException();
                RequestException(const RequestException &base);
                RequestException(t_status_code status_code);
                RequestException(t_status_code status_code, const std::string &message);
                RequestException &operator=(const RequestException &rhs);
                ~RequestException() throw ();

                virtual const char* what() const throw();
                
                std::string	get_message() const;
                std::string	get_message_from_status() const;
                t_status_code get_status_code() const;

        };

};

#endif
