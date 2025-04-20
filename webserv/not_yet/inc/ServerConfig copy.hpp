#ifndef SERVER_CONFIG_HPP
#define SERVER_CONFIG_HPP

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "constants.hpp"

class ServerConfig {

public:
    struct LocationConfig {
        std::string path;
        std::string root;
        std::string index;
        bool auto_index;
        std::vector<std::string> allowed_methods;
        std::map<std::string, std::string> cgi_extensions;
        std::string upload_store;
        size_t max_body_size;
        std::string redirect;
        t_status_code redirect_status;

        LocationConfig(): auto_index(false), max_body_size(MiB * 8) {}      
    };

    struct ServerConfigData {
        int listen_port;
        std::vector<std::string> server_name_lists;
        std::string host;
        size_t client_max_body_size;
        std::map<t_status_code, std::string> error_pages;
        std::vector<LocationConfig> locations;

        ServerConfigData(): listen_port(0), host("0.0.0.0"), client_max_body_size(MiB * 8) {}
    };

    ServerConfig();
    ~ServerConfig();

    void parse_config(const std::string &config_path);

    void display_config_lists();
    std::vector<ServerConfigData> &get_config_lists();


private:
    std::vector<ServerConfigData> config_lists;

    bool is_start_of_server_block(const std::string &line);
    bool is_start_of_location_block(const std::string &line);
    std::string extract_location_path(const std::string &line);

    void finalize_server_block(bool &in_server_block,
                            std::vector<ServerConfigData> &servers,
                            ServerConfigData &server);

    void finalize_location_block(bool &in_location_block,
                                ServerConfigData &server,
                                LocationConfig &route);

    void handle_server_directive(t_config_directive directive,
                                const std::string &value,
                                ServerConfigData &config);

    void handle_location_directive(t_config_directive directive,
                                const std::string &value,
                                LocationConfig &config);
};

#endif
