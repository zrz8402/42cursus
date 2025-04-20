#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <map>

class Server {
public:
    Server(const std::string& config_file);
    void start();

private:
    std::string _config_file;
    void setup_server();
    void listen_for_connections();
};

#endif
