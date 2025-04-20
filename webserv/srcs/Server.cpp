#include "Server.hpp"
#include "Logger.hpp"
#include "ConnectionHandler.hpp"
#include "ConfigurationManager.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>

Server::Server(const std::string& config_file) : _config_file(config_file) {}

void Server::start() {
    ConfigurationManager config_manager(_config_file);
    config_manager.load_config();
    config_manager.validate_config();

    setup_server();
    listen_for_connections();
}

void Server::setup_server() {
    // Configure the server here (e.g., create socket, bind to port, etc.)
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        Logger::error("Error creating socket");
        exit(1);
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        Logger::error("Error binding socket");
        exit(1);
    }

    listen(server_socket, 5);
}

void Server::listen_for_connections() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    while (true) {
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            Logger::error("Error accepting connection");
            continue;
        }

        ConnectionHandler handler(client_socket);
        handler.handle_request();
    }
}
