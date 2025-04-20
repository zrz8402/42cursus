// server.hpp

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <vector>
#include <map>
#include <poll.h>
#include "ServerConfig.hpp"

class Server {
public:
    Server(const std::vector<ServerConfig::ServerConfigData>& configs);
    ~Server();

    void run();

private:
    std::vector<ServerConfig::ServerConfigData> configs;
    std::map<int, ServerConfig::ServerConfigData> serverSockets;
    std::vector<struct pollfd> pollFds;
    std::map<int, std::string> clientBuffers;

    int createServerSocket(const std::string& host, int port);
    void acceptClient(int serverFd);
    void handleClient(int clientFd, size_t index);
    void closeClient(int fd, size_t index);
};

#endif
