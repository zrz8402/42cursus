#ifndef CONFIGURATIONMANAGER_HPP
#define CONFIGURATIONMANAGER_HPP

#include <string>
#include <map>

class ConfigurationManager {
public:
    ConfigurationManager(const std::string& config_file);
    void load_config();
    void validate_config();

    std::map<std::string, std::string> get_config() const;

private:
    std::string _config_file;
    std::map<std::string, std::string> _config_data;
};

#endif
