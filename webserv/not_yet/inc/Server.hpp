#ifndef SERVER_HPP
#define SERVER_HPP

#include <set>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

#include "ConnectionManager.hpp"

class Server {

    private:
    
        bool is_running;
        ServerConfig &configs;
        ConnectionManager manager;
        std::vector<int> server_sockets;

        bool has_socket(int socket);
        bool setup_sockets(ConnectionManager &manager);

    public:

        Server(ServerConfig &config);
        ~Server();

        void start();

};

#endif
