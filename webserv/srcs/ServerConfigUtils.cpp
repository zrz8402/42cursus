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


std::string ServerConfigUtils::strip_whitespaces(const std::string &s) {
    std::string::size_type start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    std::string::size_type end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

std::string ServerConfigUtils::remove_semicolon(const std::string &s) {
    std::string r = strip_whitespaces(s);

    std::string::size_type end = r.find_last_not_of("; \t\r\n");
    if (end != std::string::npos)
        r = r.substr(0, end + 1);
    else
        r = "";

    return strip_whitespaces(r);
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
        
        directive_str = strip_whitespaces(directive_str);
        value = remove_semicolon(value);
    
    } else {
        directive_str = strip_whitespaces(line);
        value = "";
    }
    
    return std::make_pair(get_config_directive(directive_str), value);
}

