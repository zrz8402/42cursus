#include "Logger.hpp"
#include "ServerConfig.hpp"
#include "ServerConfigUtils.hpp"

ServerConfig::ServerConfig() {}

ServerConfig::~ServerConfig() {}

/*
Returns the config_lists vector, which holds the configuration data.
*/
std::vector<ServerConfig::ServerConfigData> &ServerConfig::get_config_lists() {
    return this->config_lists;
}

/*
It reads the config file line by line, processes each line,
and fills in the configuration data structures
(ServerConfigData and LocationConfig).
It identifies the start of blocks (server, location),
processes the directives (e.g., listen, host, server_name, etc.),
and adds data to config_lists.
It uses Logger::debug() to output debug information,
which helps trace the config parsing process.

Improvements:
Error Handling:
Consider adding more robust error handling for invalid configurations
(e.g., incorrect values for port, missing required directives).
You can throw exceptions when encountering an invalid config line or missing fields.
Configuration Validation:
It would be beneficial to add a step for validating the entire config once it’s parsed
(ensuring that necessary directives are present and values are valid).
*/
void ServerConfig::parse_config(const std::string &config_path) {
    std::ifstream filestream(config_path.c_str());
    std::string line;
    size_t line_num = 0;

    ServerConfig::ServerConfigData current_server_config;
    ServerConfig::LocationConfig current_route_config;
    std::vector<ServerConfig::ServerConfigData> server_config_lists;

    bool in_server_block = false;
    bool in_location_block = false;

    while (std::getline(filestream, line)) {
        ++line_num;
        line = ServerConfigUtils::trim(line);

        if (line.empty() || line[0] == '#') continue;

        if (is_start_of_server_block(line)) {
            finalize_location_block(in_location_block, current_server_config, current_route_config);
            finalize_server_block(in_server_block, server_config_lists, current_server_config);

            in_server_block = true;
            current_server_config = ServerConfig::ServerConfigData();
            Logger::debug("Server block found at line " + std::to_string(line_num));
            continue;
        }

        if (in_server_block && is_start_of_location_block(line)) {
            finalize_location_block(in_location_block, current_server_config, current_route_config);

            in_location_block = true;
            current_route_config = ServerConfig::LocationConfig();
            current_route_config.auto_index = false;
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

/*
Check if a line marks the start of a new server block or location block.
Improvements:
These could be expanded to handle more edge cases,
such as unexpected whitespace or comments in the block declaration.
*/
bool ServerConfig::is_start_of_server_block(const std::string &line) {
    return line.find("server") == 0 && line.find("{") != std::string::npos;
}

bool ServerConfig::is_start_of_location_block(const std::string &line) {
    return line.find("location") == 0 && line.find("{") != std::string::npos;
}

/*
Extract the path from a location block definition.
Improvements:
You can add additional checks to ensure the path is valid 
and doesn’t contain illegal characters.
*/
std::string ServerConfig::extract_location_path(const std::string &line) {
    std::string path = line.substr(8);
    path = ServerConfigUtils::trim(path);
    size_t brace_pos = path.find("{");
    if (brace_pos != std::string::npos)
        path = path.substr(0, brace_pos);
    return ServerConfigUtils::trim(path);
}

/*
Finalizing a location or server block when the block ends (when encountering }).
It ensures that location configurations are added to their parent server config,
and server configs are added to the main config list.
Improvements:
You may want to ensure that each block is correctly closed and 
handle cases where a block ends unexpectedly (e.g., missing a closing }).
*/
void ServerConfig::finalize_location_block(bool &in_location_block,
                                           ServerConfig::ServerConfigData &server,
                                           ServerConfig::LocationConfig &route) {
    if (in_location_block) {
        server.locations.push_back(route);
        Logger::debug("Added location: " + route.path);
        in_location_block = false;
    }
}

void ServerConfig::finalize_server_block(bool &in_server_block,
                                         std::vector<ServerConfig::ServerConfigData> &servers,
                                         ServerConfig::ServerConfigData &server) {
    if (in_server_block) {
        if (!server.locations.empty() || !server.server_name_lists.empty() || server.listen_port != 0) {
            servers.push_back(server);
            Logger::debug("Added server with " + std::to_string(server.locations.size()) + " routes");
        }
        in_server_block = false;
    }
}

/*
Handle different directives within a server or location block.
Each directive is parsed and applied to the appropriate data structure
(ServerConfigData for server-level directives,
LocationConfig for location-level directives).
Improvements:
For more flexibility, consider adding support for custom directives
or unknown directives with proper error handling
(e.g., logging an error message instead of throwing an exception).
You can add validation to ensure that directives are not misconfigured
(e.g., listen without a valid port).
*/
void ServerConfig::handle_server_directive(t_config_directive directive,
                                           const std::string &value,
                                           ServerConfigData &config) {
    size_t delimiter_pos;

    switch (directive) {
        case DIRECTIVE_LISTEN:
            delimiter_pos = value.find(":");
            if (delimiter_pos != std::string::npos) {
                config.host = value.substr(0, delimiter_pos);
                config.listen_port = std::atoi(value.substr(delimiter_pos + 1).c_str());
            } else {
                config.listen_port = std::atoi(value.c_str());
                config.host = "0.0.0.0";
            }

            if (config.listen_port < 0 || config.listen_port > 65535) {
                throw std::runtime_error("Port " + std::to_string(config.listen_port) + " is out of range. (Please use a port in range between 0 and 65535)");
            }
            break;

        case DIRECTIVE_HOST:
            config.host = value;
            break;

        case DIRECTIVE_SERVER_NAME:
            {
                std::istringstream name_stream(value);
                std::string name;
                while (name_stream >> name) {
                    config.server_name_lists.push_back(name);
                }
            }
            break;

        case DIRECTIVE_ERROR_PAGE:
            {
                std::string status_code, page;
                std::istringstream error_page_stream(value);
                error_page_stream >> status_code;
                std::getline(error_page_stream, page);
                config.error_pages[static_cast<t_status_code>(std::atoi(status_code.c_str()))] = ServerConfigUtils::trim(page);
            }
            break;

        case DIRECTIVE_CLIENT_MAX_BODY_SIZE:
            config.client_max_body_size = static_cast<size_t>(std::atoi(value.c_str())) * 1024 * 1000;
            break;

        default:
            break;
    }
}

void ServerConfig::handle_location_directive(t_config_directive directive,
                                             const std::string &value,
                                             LocationConfig &config) {
    switch (directive) {
        case DIRECTIVE_ALLOWED_METHODS:
            {
                std::string method;
                std::istringstream method_stream(value);
                while (method_stream >> method) {
                    config.allowed_methods.push_back(method);
                }
            }
            break;

        case DIRECTIVE_AUTOINDEX:
            config.auto_index = (value == "on");
            break;

        case DIRECTIVE_ROOT:
            config.root = value;
            break;

        case DIRECTIVE_INDEX:
            config.index = value;
            break;

        case DIRECTIVE_CGI_PASS:
            {
                std::vector<std::string> tokens = ServerConfigUtils::split(value);

                if (tokens.size() != 2) {
                    Logger::error("Failed to parse CGI extensions. (too few or too many arguments)");
                    break;
                }

                if (tokens[0][0] != '.') {
                    Logger::error("Failed to parse CGI extensions. (Extensions need to start with '.')");
                    break;
                }

                config.cgi_extensions[tokens[0]] = tokens[1];
            }
            break;

        case DIRECTIVE_UPLOAD_STORE:
            config.upload_store = value;
            break;

        case DIRECTIVE_CLIENT_MAX_BODY_SIZE:
            config.max_body_size = static_cast<size_t>(std::atoi(value.c_str())) * 1024 * 1000;
            break;
        case DIRECTIVE_RETURN:
            {
                std::string status_code;
                std::istringstream return_stream(value);
                return_stream >> status_code >> config.redirect;
                config.redirect_status = static_cast<t_status_code>(std::atoi(status_code.c_str()));
            }
            break;

        default:
            break;
    }
}
