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

        struct RouteConfigData {

            std::string path;
            std::string redirect_target;
            std::string root_path;
            std::string index_path;
            std::string upload_path;
            std::vector<std::string> allowed_methods;
            std::map<std::string, std::string> cgi_extensions;
            t_status_code redirect_status;
            size_t max_body_size;
            bool use_auto_index;
        
            RouteConfigData(): max_body_size(MiB * 8), use_auto_index(false) {}        
        };
        
        struct ServerConfigData {
        
            std::string host;
            int port;
            size_t max_body_size;
            std::vector<std::string> server_name_lists;
            std::vector<RouteConfigData> route_config_lists;
            std::map<t_status_code, std::string> error_page;
        
            ServerConfigData(): host("0.0.0.0"), port(0), max_body_size(MiB * 8) {}
        
        };

        ServerConfig();
        ~ServerConfig();

        void display_config_lists();
        std::vector<ServerConfigData> &get_config_lists();

        void parse_config_file(const std::string &config_path);

    private:
        std::vector<ServerConfigData> config_lists;

        bool is_start_of_server_block(const std::string &line);
        bool is_start_of_location_block(const std::string &line);
        std::string extract_location_path(const std::string &line);

        // Finalization helpers
        void finalize_server_block(bool &in_server_block,
                                std::vector<ServerConfigData> &servers,
                                ServerConfigData &server);

        void finalize_location_block(bool &in_location_block,
                                    ServerConfigData &server,
                                    RouteConfigData &route);

        // Directive handling
        void handle_server_directive(t_config_directive directive,
                                    const std::string &value,
                                    ServerConfigData &config);

        void handle_location_directive(t_config_directive directive,
                                    const std::string &value,
                                    RouteConfigData &config);
};

#endif
