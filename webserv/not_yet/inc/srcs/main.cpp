/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:18:24 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/04/20 11:03:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Logger.hpp"
#include "constants.hpp"
#include "ServerConfig.hpp"

int main(int argc, char **argv) {

    std::vector<std::string> args;

    for (int idx = 1; idx < argc; ++idx) {
        args.push_back(std::string(argv[idx]));
    }

    try {

        bool show_config = false;
        std::string config_path = "./config/default.conf";

        for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it) {
            const std::string& arg = *it;
            if (arg.size() >= 5 && arg.substr(arg.size() - 5) == ".conf") {
                config_path = arg;
                break;
            }
        }

        if (std::find(args.begin(), args.end(), "-t") != args.end()) {
            show_config = true;
        }

        ServerConfig server_config;
        server_config.parse_config(config_path);

        if (show_config) {
            server_config.display_config_lists();
            return 0;
        }

        Server server(server_config);
        server.start();

    }

    catch (const std::exception &e) {
        Logger::error(e.what());
        return 1;
    }

}
