#include "Server.hpp"
#define BUFFER_SIZE 4096

Server::Server(const std::vector<ServerConfig::ServerConfigData>& configs)
    : configs(configs) {
    for (size_t i = 0; i < configs.size(); ++i) {
        const ServerConfig::ServerConfigData& conf = configs[i];
        int sockfd = createServerSocket(conf.host, conf.listen_port);

        serverSockets[sockfd] = conf;

        struct pollfd pfd;
        pfd.fd = sockfd;
        pfd.events = POLLIN;
        pollFds.push_back(pfd);

        std::cout << "[INFO] Listening on " << conf.host << ":" << conf.listen_port << " (fd=" << sockfd << ")\n";
    }
}

Server::~Server() {
    for (size_t i = 0; i < pollFds.size(); ++i) {
        close(pollFds[i].fd);
    }
}

int Server::createServerSocket(const std::string& host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) throw std::runtime_error("Failed to create socket");

    int yes = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = (host == "0.0.0.0") ? INADDR_ANY : inet_addr(host.c_str());

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        throw std::runtime_error("Failed to bind to " + host + ":" + std::to_string(port));

    if (listen(sockfd, SOMAXCONN) < 0)
        throw std::runtime_error("Listen failed on port " + std::to_string(port));

    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    return sockfd;
}

void Server::run() {
    while (true) {
        int ret = poll(&pollFds[0], pollFds.size(), -1);
        if (ret < 0) throw std::runtime_error("poll() failed");

        for (size_t i = 0; i < pollFds.size(); ++i) {
            int fd = pollFds[i].fd;

            if (serverSockets.count(fd) && pollFds[i].revents & POLLIN) {
                acceptClient(fd);
            } else if (pollFds[i].revents & POLLIN) {
                handleClient(fd, i);
            }
        }
    }
}

void Server::acceptClient(int serverFd) {
    int clientFd = accept(serverFd, NULL, NULL);
    if (clientFd >= 0) {
        fcntl(clientFd, F_SETFL, O_NONBLOCK);
        struct pollfd newClient;
        newClient.fd = clientFd;
        newClient.events = POLLIN;
        pollFds.push_back(newClient);
        clientBuffers[clientFd] = "";
        std::cout << "[+] New client connected: " << clientFd << std::endl;
    }
}

void Server::handleClient(int clientFd, size_t index) {
    char buffer[BUFFER_SIZE];
    ssize_t n = read(clientFd, buffer, BUFFER_SIZE);

    if (n <= 0) {
        closeClient(clientFd, index);
    } else {
        clientBuffers[clientFd] += std::string(buffer, n);
        if (clientBuffers[clientFd].find("\r\n\r\n") != std::string::npos) {
            std::string response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
            write(clientFd, response.c_str(), response.size());
            closeClient(clientFd, index);
        }
    }
}

void Server::closeClient(int fd, size_t index) {
    close(fd);
    pollFds.erase(pollFds.begin() + index);
    clientBuffers.erase(fd);
    std::cout << "[-] Closed connection: " << fd << std::endl;
}
