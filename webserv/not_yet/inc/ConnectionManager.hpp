#ifndef CONNECTION_MANAGER_HPP
#define CONNECTION_MANAGER_HPP

#include <cstring>

#include "constants.hpp"
#include "Connection.hpp"
#include "ServerConfig.hpp"

class ConnectionManager {

    private:
        std::map<int, Connection> connections;
        std::map<int, ServerConfig::ServerConfigData> server_data;
        std::vector<ServerConfig::ServerConfigData> config_lists;

    public:

        static int epoll_socket;

        ConnectionManager();
        ~ConnectionManager();

        int open_connection(int fd, ServerConfig::ServerConfigData &config);
        bool close_connection(int fd);

        bool socket_read(int fd);
        bool socket_write(int fd);

        std::map<int, ServerConfig::ServerConfigData> get_server_data();
        ServerConfig::ServerConfigData *get_server_from_fd(int fd);
        Connection *get_connection_from_fd(int fd);

        static void set_epoll_socket(int epoll_fd);

        size_t remove_expired_connections();

        size_t add_server(int fd, ServerConfig::ServerConfigData server);
        size_t add_server(ServerConfig::ServerConfigData server);

        Connection *find_connection(int fd);


};

#endif
