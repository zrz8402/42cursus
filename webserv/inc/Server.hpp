#ifndef SERVER_HPP
#define SERVER_HPP

#include <dirent.h>
#include <sys/stat.h>
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
#include "Response.hpp"
#include "Router.hpp"

class ServerConfig;

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

    bool is_directory(const char* path);
    void generate_autoindex(const char* dir_path, char* buffer);
    void execute_cgi_script(const char* script_path, const std::map<std::string, std::string>& headers, int clientFd);

};

#endif
