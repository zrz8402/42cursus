#include "Router.hpp"

Router::Router() {}

Router::~Router() {}

ServerConfig::RouteConfigData *Router::find_route_from_path(std::vector<ServerConfig::RouteConfigData> &routes, const std::string &target_path) {

    for (
        std::vector<ServerConfig::RouteConfigData>::iterator it = routes.begin();
        it != routes.end();
        ++it
    ) {
        if (target_path == it->path) {
            Logger::debug("Found exact matching route: '" + it->path + "'");
            return &(*it);
        }
    }

    Logger::debug("Exact match not found, looking for similar route...");

    size_t best_match_len = 0;
    ServerConfig::RouteConfigData *best_match = NULL;

    for (
        std::vector<ServerConfig::RouteConfigData>::iterator it = routes.begin();
        it != routes.end();
        ++it
    ) {
        
        if (it->path == "/upload" && target_path.find("/upload/") == 0) {
            Logger::debug("Found /upload match");
            return &(*it);
        }

        if (it->path.length() > target_path.length()) {
            Logger::debug("Skipping (route path too long)");
            continue;
        }

        if (target_path.find(it->path) == 0) {

            Logger::debug("Found prefix match");
            
            if (it->path.length() > best_match_len) {

                best_match_len = it->path.length();
                best_match = &(*it);
                
                Logger::debug("New best match: '" + it->path + "' (length: " + to_string(best_match_len) + ")");
            
            }
        }
    }

    if (best_match) {
        return best_match;
    }

    Logger::debug("No matching route found");

    return NULL;

}
