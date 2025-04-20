#include "ServerConfig.hpp"
#include <stdexcept>

/*
Match a server block based on the provided host and port.
It first tries to match both the host and port,
and if no match is found based on the host,
it will fallback to matching just the port.
*/
const ServerConfig::ServerConfigData& get_matching_server_config(
    int port,
    const std::string& host,
    const std::vector<ServerConfig::ServerConfigData>& servers
) {
    for (size_t i = 0; i < servers.size(); ++i) {
        const ServerConfig::ServerConfigData& server = servers[i];
        if (server.listen_port == port) {
            for (size_t j = 0; j < server.server_name_lists.size(); ++j) {
                if (server.server_name_lists[j] == host)
                    return server;
            }
        }
    }

    // Fallback: match just port if no server_name matched
    for (size_t i = 0; i < servers.size(); ++i) {
        const ServerConfig::ServerConfigData& server = servers[i];
        if (server.listen_port == port)
            return server;
    }

    throw std::runtime_error("No matching server config found for host " + host);
    // throw std::runtime_error("No matching server config found for host " + host + ", port " + std::to_string(port));
}


/*
Find the most appropriate location block 
for a given URI from the server’s configuration.
It iterates through the available location blocks and 
selects the one with the longest matching path prefix.
*/
const ServerConfig::LocationConfig& get_matching_route(
    const std::string& uri,
    const ServerConfig::ServerConfigData& server
) {
    size_t best_match_len = 0;
    const ServerConfig::LocationConfig* best_match = NULL;

    for (size_t i = 0; i < server.locations.size(); ++i) {
        const ServerConfig::LocationConfig& route = server.locations[i];
        if (uri.find(route.path) == 0 && route.path.length() > best_match_len) {
            best_match_len = route.path.length();
            best_match = &route;
        }
    }

    if (best_match != NULL)
        return *best_match;

    throw std::runtime_error("No matching location block for URI " + uri);
}
