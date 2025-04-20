#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Logger.hpp"
#include "constants.hpp"
#include "ServerConfig.hpp"

class Router {

    public:

        Router();
        ~Router();

        static ServerConfig::RouteConfigData *find_route_from_path(
            std::vector<ServerConfig::RouteConfigData> &routes, 
            const std::string &target_path
        );

};

#endif
