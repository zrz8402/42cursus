#ifndef SERVER_CONFIG_UTILS
#define SERVER_CONFIG_UTILS

#include <map>
#include <string>
#include <vector>
#include <sstream>

#include "constants.hpp"

class ServerConfigUtils {

    public:
        static std::vector<std::string> split(const std::string& str);
        static std::string trim(const std::string &s);
        static std::string remove_semicolon(const std::string &s);
        static t_config_directive get_config_directive(std::string &str);
        static std::pair<t_config_directive, std::string> parse_directive(const std::string &line);

};

#endif
