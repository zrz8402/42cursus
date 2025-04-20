#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <vector>
#include "ServerConfig.hpp"

// Matches the Host+Port to a server config block
const ServerConfig::ServerConfigData& get_matching_server_config(
    int port,
    const std::string& host,
    const std::vector<ServerConfig::ServerConfigData>& servers);

// Matches the URI to the best route block inside the matched server
const ServerConfig::LocationConfig& get_matching_route(
    const std::string& uri,
    const ServerConfig::ServerConfigData& server);

#endif