#include "Logger.hpp"
#include "ServerConfig.hpp"
#include "ServerConfigUtils.hpp"

ServerConfig::ServerConfig() {}

ServerConfig::~ServerConfig() {}

std::vector<ServerConfig::ServerConfigData> &ServerConfig::get_config_lists() {
    return this->config_lists;
}

void ServerConfig::parse_config_file(const std::string &config_path) {
    std::ifstream filestream(config_path.c_str());
    std::string line;
    size_t line_num = 0;

    ServerConfig::ServerConfigData current_server_config;
    ServerConfig::RouteConfigData current_route_config;
    std::vector<ServerConfig::ServerConfigData> server_config_lists;

    bool in_server_block = false;
    bool in_location_block = false;

    while (std::getline(filestream, line)) {
        ++line_num;
        line = ServerConfigUtils::strip_whitespaces(line);

        if (line.empty() || line[0] == '#') continue;

        if (is_start_of_server_block(line)) {
            finalize_location_block(in_location_block, current_server_config, current_route_config);
            finalize_server_block(in_server_block, server_config_lists, current_server_config);

            in_server_block = true;
            current_server_config = ServerConfig::ServerConfigData();
            Logger::debug("Server block found at line " + to_string(line_num));
            continue;
        }

        if (in_server_block && is_start_of_location_block(line)) {
            finalize_location_block(in_location_block, current_server_config, current_route_config);

            in_location_block = true;
            current_route_config = ServerConfig::RouteConfigData();
            current_route_config.use_auto_index = false;
            current_route_config.path = extract_location_path(line);
            Logger::debug("Location block: " + current_route_config.path);
            continue;
        }

        if (line == "}") {
            if (in_location_block) {
                finalize_location_block(in_location_block, current_server_config, current_route_config);
            } else if (in_server_block) {
                finalize_server_block(in_server_block, server_config_lists, current_server_config);
            }
            continue;
        }

        std::pair<t_config_directive, std::string> directive_data = ServerConfigUtils::parse_directive(line);
        t_config_directive directive = directive_data.first;
        std::string value = directive_data.second;

        if (in_server_block && !in_location_block) {
            handle_server_directive(directive, value, current_server_config);
        } else if (in_location_block) {
            handle_location_directive(directive, value, current_route_config);
        }
    }

    finalize_location_block(in_location_block, current_server_config, current_route_config);
    finalize_server_block(in_server_block, server_config_lists, current_server_config);
    filestream.close();
    this->config_lists = server_config_lists;
}

bool ServerConfig::is_start_of_server_block(const std::string &line) {
    return line.find("server") == 0 && line.find("{") != std::string::npos;
}

bool ServerConfig::is_start_of_location_block(const std::string &line) {
    return line.find("location") == 0 && line.find("{") != std::string::npos;
}

std::string ServerConfig::extract_location_path(const std::string &line) {
    std::string path = line.substr(8);
    path = ServerConfigUtils::strip_whitespaces(path);
    size_t brace_pos = path.find("{");
    if (brace_pos != std::string::npos)
        path = path.substr(0, brace_pos);
    return ServerConfigUtils::strip_whitespaces(path);
}

void ServerConfig::finalize_location_block(bool &in_location_block,
                                           ServerConfig::ServerConfigData &server,
                                           ServerConfig::RouteConfigData &route) {
    if (in_location_block) {
        server.route_config_lists.push_back(route);
        Logger::debug("Added location: " + route.path);
        in_location_block = false;
    }
}

void ServerConfig::finalize_server_block(bool &in_server_block,
                                         std::vector<ServerConfig::ServerConfigData> &servers,
                                         ServerConfig::ServerConfigData &server) {
    if (in_server_block) {
        if (!server.route_config_lists.empty() || !server.server_name_lists.empty() || server.port != 0) {
            servers.push_back(server);
            Logger::debug("Added server with " + to_string(server.route_config_lists.size()) + " routes");
        }
        in_server_block = false;
    }
}

void ServerConfig::display_config_lists() {

    const std::vector<ServerConfig::ServerConfigData> servers_configs = this->config_lists;

    for (size_t idx = 0; idx < servers_configs.size(); idx++) {

        std::cout << "\nServer #" << idx + 1 << ":\n" << std::endl;
        std::cout << "\tHost: " << servers_configs[idx].host << std::endl;
        std::cout << "\tPort: " << servers_configs[idx].port << std::endl;
        std::cout << "\tMax body size: " << servers_configs[idx].max_body_size << std::endl;


        std::cout << "\tServer Names: ";

        for (size_t name_idx = 0; name_idx < servers_configs[idx].server_name_lists.size(); name_idx++) {
            std::cout << servers_configs[idx].server_name_lists[name_idx] << " ";
        }

        std::cout << std::endl;
        std::cout << "\tError pages: " << std::endl;

        for (
            std::map<t_status_code, std::string>::const_iterator iterator = servers_configs[idx].error_page.begin();
            iterator != servers_configs[idx].error_page.end();
            iterator++
        ) {
            std::cout << "\t\t- " << iterator->first << ": " << iterator->second << std::endl;
        }

        std::cout << std::endl;
        std::cout << "\tRoutes: " << std::endl;

        for (size_t route_idx = 0; route_idx < servers_configs[idx].route_config_lists.size(); route_idx++) {    
            std::cout << "\t\tPath: " << servers_configs[idx].route_config_lists[route_idx].path << std::endl;
            std::cout << "\t\tRoot: " << servers_configs[idx].route_config_lists[route_idx].root_path << std::endl;
            std::cout << "\t\tIndex: " << servers_configs[idx].route_config_lists[route_idx].index_path << std::endl;
            
            std::cout << "\t\tMethods: " << std::endl;

            for (
                size_t method_idx = 0;
                method_idx < servers_configs[idx].route_config_lists[route_idx].allowed_methods.size();
                method_idx++
            ) {
                std::cout 
                    << "\t\t\t- "
                    << servers_configs[idx].route_config_lists[route_idx].allowed_methods[method_idx]
                    << std::endl;
            }
            std::cout << std::endl;

            if (servers_configs[idx].route_config_lists[route_idx].cgi_extensions.size() == 0) {
                std::cout << "\t\tCGI Extensions: (none)" << std::endl;
            } else {
                std::cout << "\t\tCGI Extensions:" << std::endl;

                std::map<std::string, std::string> cgi = servers_configs[idx].route_config_lists[route_idx].cgi_extensions;
                
                for (
                    std::map<std::string, std::string>::iterator iter = cgi.begin();
                    iter != cgi.end();
                    ++iter
                ) {
                    std::cout
                        << "\t\t\t- "
                        << iter->first << " -> " << iter->second
                        << std::endl;
                }
            }
            std::cout << std::endl;

            std::cout << "\t\tUpload Store: " << servers_configs[idx].route_config_lists[route_idx].upload_path << std::endl;
            std::cout << "\t\tAuto Index: " << (servers_configs[idx].route_config_lists[route_idx].use_auto_index ? "on" : "off") << std::endl;
            std::cout << "\t\tMax body size: " << servers_configs[idx].route_config_lists[route_idx].max_body_size << std::endl;
        }

    }
    std::cout << std::endl;
}
