#include <iostream>
#include "Logger.hpp"
#include "constants.hpp"
#include "ServerConfig.hpp"
#include "ServerConfigUtils.hpp"
#include "Server.hpp"
#include "Router.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include <iostream>
#include <stdexcept>
#include "Server.hpp"
#include "ConfigurationManager.hpp"

int main(int argc, char **argv) {
    // Ensure proper usage of the program
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config_file.conf>" << std::endl;
        return 1;
    }

    std::string config_path = argv[1]; // Path to the config file

    try {
        // Initialize ConfigurationManager with the given config file
        ConfigurationManager config_manager(config_path);

        // Load the configuration
        config_manager.load_config();

        // Validate the configuration
        config_manager.validate_config();

        // Pass the loaded configuration to the server
        Server server(config_path);
        server.start(); // Start the server

    } catch (const std::exception& e) {
        // Handle any exceptions thrown during the process
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
