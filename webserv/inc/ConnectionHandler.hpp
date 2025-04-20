#ifndef CONNECTIONHANDLER_HPP
#define CONNECTIONHANDLER_HPP

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class ConnectionHandler {
public:
    ConnectionHandler(int socket_fd);
    void handle_request();

private:
    int _socket_fd;
    void send_response(const std::string& response);
};

#endif
