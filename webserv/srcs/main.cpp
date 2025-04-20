#include <iostream>
#include "Logger.hpp"
#include "constants.hpp"
#include "ServerConfig.hpp"
#include "ServerConfigUtils.hpp"
#include "Server.hpp"
#include "Router.hpp"
#include "Request.hpp"
#include "Response.hpp"

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         std::cerr << "Usage: " << argv[0] << " <config_file.conf>" << std::endl;
//         return 1;
//     }

//     std::string config_path = argv[1];
//     ServerConfig config;

//     try {
//         config.parse_config(config_path);
//         const std::vector<ServerConfig::ServerConfigData>& server_configs = config.get_config_lists();

//         // Debug print of parsed config
//         ServerConfigUtils::display_config_lists(server_configs);

//         Server server(server_configs);
//         server.run();
//     }
//     catch (const std::exception& e) {
//         std::cerr << "[ERROR] " << e.what() << std::endl;
//         return 1;
//     }

//     return 0;
// }
