#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Logger.hpp"
#include "constants.hpp"
#include "ServerConfig.hpp"

class Router {

    public:

        Router();
        ~Router();

        static ServerConfig::LocationConfig *find_route_from_path(
            std::vector<ServerConfig::LocationConfig> &routes, 
            const std::string &target_path
        );

};

#endif
