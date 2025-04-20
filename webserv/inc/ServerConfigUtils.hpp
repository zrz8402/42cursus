#ifndef SERVER_CONFIG_UTILS
#define SERVER_CONFIG_UTILS

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "constants.hpp"
#include "ServerConfig.hpp"

class ServerConfig;

class ServerConfigUtils {

public:
    static std::vector<std::string> split(const std::string& str);
    static std::string trim(const std::string &s);
    static std::string remove_semicolon(const std::string &s);
    static t_config_directive get_config_directive(std::string &str);
    static std::pair<t_config_directive, std::string> parse_directive(const std::string &line);

    // Display config list and formatting
    static void display_config_lists(const std::vector<ServerConfig::ServerConfigData>& configs);
    static void print_server_config(const ServerConfig::ServerConfigData& config, size_t idx);
    static void print_server_names(const std::vector<std::string>& names);
    static void print_error_pages(const std::map<t_status_code, std::string>& pages);
    static void print_methods(const std::vector<std::string>& methods);
    static void print_cgi(const std::map<std::string, std::string>& cgi);
    static void print_location(const ServerConfig::LocationConfig& loc);
};

#endif