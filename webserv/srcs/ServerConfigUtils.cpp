#include "ServerConfigUtils.hpp"

std::vector<std::string> ServerConfigUtils::split(const std::string& str) {
    std::string word;
    std::istringstream iss(str);
    std::vector<std::string> result;
    
    while (iss >> word) {
        result.push_back(word);
    }
    return result;
}

std::string ServerConfigUtils::trim(const std::string &s) {
    std::string::size_type start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    std::string::size_type end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

std::string ServerConfigUtils::remove_semicolon(const std::string &s) {
    std::string r = trim(s);

    std::string::size_type end = r.find_last_not_of("; \t\r\n");
    if (end != std::string::npos)
        r = r.substr(0, end + 1);
    else
        r = "";

    return trim(r);
}

t_config_directive ServerConfigUtils::get_config_directive(std::string &str) {

    if (str == "listen") return DIRECTIVE_LISTEN;
    if (str == "host") return DIRECTIVE_HOST;
    if (str == "server_name") return DIRECTIVE_SERVER_NAME;
    if (str == "error_page") return DIRECTIVE_ERROR_PAGE;
    if (str == "client_max_body_size") return DIRECTIVE_CLIENT_MAX_BODY_SIZE;
    if (str == "methods" || str == "allowed_methods") return DIRECTIVE_ALLOWED_METHODS;
    if (str == "autoindex") return DIRECTIVE_AUTOINDEX;
    if (str == "root") return DIRECTIVE_ROOT;
    if (str == "index") return DIRECTIVE_INDEX;
    if (str == "cgi_pass") return DIRECTIVE_CGI_PASS;
    if (str == "cgi_extension") return DIRECTIVE_CGI_EXTENSION;
    if (str == "upload_store") return DIRECTIVE_UPLOAD_STORE;
    if (str == "return") return DIRECTIVE_RETURN;

    throw std::runtime_error("Unknown directive: " + str);
}

std::pair<t_config_directive, std::string> ServerConfigUtils::parse_directive(const std::string &line) {

    std::string directive_str, value;
    
    size_t pos = line.find_first_of(" \t");
    if (pos != std::string::npos) {

        directive_str = line.substr(0, pos);
        value = line.substr(pos + 1);
        
        directive_str = trim(directive_str);
        value = remove_semicolon(value);

    } else {
        directive_str = trim(line);
        value = "";
    }
    
    return std::make_pair(get_config_directive(directive_str), value);
}

void ServerConfigUtils::print_server_names(const std::vector<std::string>& names) {
    std::cout << "\tServer Name: ";
    for (size_t i = 0; i < names.size(); ++i)
        std::cout << names[i] << " ";
    std::cout << std::endl;
}

void ServerConfigUtils::print_error_pages(const std::map<t_status_code, std::string>& pages) {
    std::cout << "\tError pages:\n";
    for (std::map<t_status_code, std::string>::const_iterator it = pages.begin(); it != pages.end(); ++it)
        std::cout << "\t\t- " << it->first << ": " << it->second << std::endl;
}

void ServerConfigUtils::print_methods(const std::vector<std::string>& methods) {
    std::cout << "\t\tMethods:\n";
    for (size_t i = 0; i < methods.size(); ++i)
        std::cout << "\t\t\t- " << methods[i] << std::endl;
}

void ServerConfigUtils::print_cgi(const std::map<std::string, std::string>& cgi) {
    if (cgi.empty()) {
        std::cout << "\t\tCGI Extensions: (none)\n";
        return;
    }

    std::cout << "\t\tCGI Extensions:\n";
    for (std::map<std::string, std::string>::const_iterator it = cgi.begin(); it != cgi.end(); ++it)
        std::cout << "\t\t\t- " << it->first << " -> " << it->second << std::endl;
}

void ServerConfigUtils::print_location(const ServerConfig::LocationConfig& loc) {
    std::cout << "\t\tPath: " << loc.path << std::endl;
    std::cout << "\t\tRoot: " << loc.root << std::endl;
    std::cout << "\t\tIndex: " << loc.index << std::endl;
    std::cout << "\t\tClient max body size: " << loc.max_body_size << std::endl;
    print_methods(loc.allowed_methods);
    print_cgi(loc.cgi_extensions);
    std::cout << "\t\tUpload Store: " << loc.upload_store << std::endl;
    std::cout << "\t\tAuto Index: " << (loc.auto_index ? "on" : "off") << std::endl;
    std::cout << std::endl;
}

void ServerConfigUtils::print_server_config(const ServerConfig::ServerConfigData& config, size_t idx) {
    std::cout << "\nServer #" << idx + 1 << ":\n";
    std::cout << "\tListen_port: " << config.listen_port << std::endl;
    print_server_names(config.server_name_lists);
    std::cout << "\tHost: " << config.host << std::endl;
    std::cout << "\tClient max body size: " << config.client_max_body_size << std::endl;
    print_error_pages(config.error_pages);
    
    std::cout << "\tLocation:\n";
    for (size_t i = 0; i < config.locations.size(); ++i)
    print_location(config.locations[i]);
}

void ServerConfigUtils::display_config_lists(const std::vector<ServerConfig::ServerConfigData>& configs) {
    for (size_t i = 0; i < configs.size(); ++i)
    print_server_config(configs[i], i);
    std::cout << std::endl;
}
