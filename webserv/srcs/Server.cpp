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

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        throw std::runtime_error("Failed to bind to " + host);
        // throw std::runtime_error("Failed to bind to " + host + ":" + std::to_string(port));
    }

    if (listen(sockfd, SOMAXCONN) < 0) {
        throw std::runtime_error("Listen failed on port ");
        // throw std::runtime_error("Listen failed on port " + std::to_string(port));
    }

    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    return sockfd;
}

void Server::run() {
    while (true) {
        int ret = poll(&pollFds[0], pollFds.size(), -1);
        if (ret < 0) {
            throw std::runtime_error("poll() failed");
        }

        for (size_t i = 0; i < pollFds.size(); ++i) {
            int fd = pollFds[i].fd;

            // Handle new incoming connection (server socket)
            if (serverSockets.count(fd) && (pollFds[i].revents & POLLIN)) {
                acceptClient(fd);  // Accept new client connection
            }
            // Handle incoming data from clients
            else if (pollFds[i].revents & POLLIN) {
                // Read the request and handle it
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
    char buffer[8192];
    ssize_t bytesRead = recv(clientFd, buffer, sizeof(buffer) - 1, 0);

    if (bytesRead <= 0) {
        closeClient(clientFd, index);
        return;
    }

    buffer[bytesRead] = '\0';
    clientBuffers[clientFd] += buffer;

    Request request;
    if (!request.parse(clientBuffers[clientFd])) {
        closeClient(clientFd, index);
        return;
    }

    try {
        const ServerConfig::ServerConfigData& server = get_matching_server_config(
            request.get_port(), request.get_host(), configs
        );

        const ServerConfig::LocationConfig& location = get_matching_route(
            request.get_path(), server
        );

        Response response(request, server, location);
        std::string httpResponse = response.build_response();

        send(clientFd, httpResponse.c_str(), httpResponse.size(), 0);
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        std::string errResp = "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 0\r\n\r\n";
        send(clientFd, errResp.c_str(), errResp.size(), 0);
    }

    closeClient(clientFd, index);
}

void Server::closeClient(int fd, size_t index) {
    close(fd);
    pollFds.erase(pollFds.begin() + index);
    clientBuffers.erase(fd);
    std::cout << "[-] Closed connection: " << fd << std::endl;
}

bool Server::is_directory(const char* path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return false;
    }
    return S_ISDIR(statbuf.st_mode);
}

void Server::generate_autoindex(const char* dir_path, char* buffer) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        strcpy(buffer, "<p>Error reading directory</p>");
        return;
    }

    struct dirent* entry;
    strcpy(buffer, "<html><body><h1>Directory Listing</h1><ul>");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        strcat(buffer, "<li><a href=\"");
        strcat(buffer, entry->d_name);
        strcat(buffer, "\">");
        strcat(buffer, entry->d_name);
        strcat(buffer, "</a></li>");
    }

    closedir(dir);
    strcat(buffer, "</ul></body></html>");
}

void Server::execute_cgi_script(const char* script_path, const std::map<std::string, std::string>& headers, int clientFd) {
    // Build command line for CGI script
    std::string command = script_path;
    for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it) {
        command += " " + it->first + "=" + it->second;
    }

    // Execute CGI script
    FILE* fp = popen(command.c_str(), "r");
    if (fp == NULL) {
        std::cerr << "Error executing CGI script: " << command << std::endl;
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        send(clientFd, buffer, strlen(buffer), 0);
    }

    fclose(fp);
}
