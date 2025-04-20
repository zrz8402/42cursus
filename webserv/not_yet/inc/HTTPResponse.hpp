#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <string>
#include <map>

#include "constants.hpp"
#include "Logger.hpp"
#include "HTTPRequest.hpp"

class HTTPResponse
{
    private:
        t_status_code code;
        std::map<std::string, std::string> headers;
        std::string body;

    public:
        HTTPResponse();
        ~HTTPResponse();

        void set_status(t_status_code code);
        void set_header(const std::string& name, const std::string& value);
        void set_content_type(const std::string& type);
        void set_body(const std::string& content);

        std::string get_header(const std::string& name) const;

        std::string serialize() const;        

        void clear();

        static std::string get_message_from_status(t_status_code code);
        static std::string get_mime_type(const std::string &file_extension);
};

#endif
