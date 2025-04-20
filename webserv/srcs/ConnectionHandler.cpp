#include "ConnectionHandler.hpp"
#include "RequestParser.hpp"
#include "ResponseBuilder.hpp"
#include "Logger.hpp"
#include <unistd.h>
#include <string.h>

ConnectionHandler::ConnectionHandler(int socket_fd) : _socket_fd(socket_fd) {}

void ConnectionHandler::handle_request() {
    char buffer[1024];
    ssize_t bytes_received = recv(_socket_fd, buffer, sizeof(buffer), 0);
    
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        std::string request_data(buffer);
        
        RequestParser parser;
        if (parser.parse(request_data)) {
            ResponseBuilder response(parser);
            std::string response_data = response.build_response();
            send_response(response_data);
        } else {
            Logger::error("Failed to parse request");
        }
    }

    close(_socket_fd);
}

void ConnectionHandler::send_response(const std::string& response) {
    send(_socket_fd, response.c_str(), response.length(), 0);
}