#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Router.hpp"
#include "Logger.hpp"
#include "constants.hpp"
#include "ServerConfig.hpp"
#include "HTTPRequest.hpp"

class Connection {

    private:

        int fd;
        int epoll_socket;

        bool is_ready;
        bool is_header_done;
        bool is_request_done;

        size_t body_length;
        size_t content_length;

        std::string boundary;
        std::string request_buffer;
        std::string response_buffer;
        std::vector<char> raw_post_body;
        
        time_t expires_time;
        ServerConfig::ServerConfigData config;
        std::vector<ServerConfig::LocationConfig> route_configs;

        void set_nonblock_mode();

    public:

        Connection(int fd, ServerConfig::ServerConfigData &config);
        Connection &operator=(const Connection &rhs);
        ~Connection();

        int get_socket();

        void clear();
        void update_expiration_time();

        bool should_retry();

        bool set_expires_time(time_t current_timestamp);
        
        bool get_header_status();
        bool get_request_status();

        std::string get_response_buffer();
        ssize_t truncate_response_buffer(ssize_t n_sended);

        bool is_need_to_write();
        bool is_connection_expired(time_t current_timestamp);

        bool join_request_buffer(char *buffer, size_t length, std::vector<ServerConfig::ServerConfigData> servers);

        bool parse_request(HTTPRequest &request);
        bool ready(HTTPResponse &response, bool send = false);

};

#endif
