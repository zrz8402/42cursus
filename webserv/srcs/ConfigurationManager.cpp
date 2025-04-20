#include "ConfigurationManager.hpp"
#include "Logger.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

ConfigurationManager::ConfigurationManager(const std::string& config_file) : _config_file(config_file) {}

void ConfigurationManager::load_config() {
    std::ifstream file(_config_file);
    if (!file.is_open()) {
        Logger::error("Failed to open config file: " + _config_file);
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string key, value;
        if (std::getline(ss, key, '=')) {
            std::getline(ss, value);
            _config_data[key] = value;
        }
    }
    file.close();
}

void ConfigurationManager::validate_config() {
    if (_config_data.find("server_port") == _config_data.end()) {
        Logger::error("Missing server port in config");
    }
}

std::map<std::string, std::string> ConfigurationManager::get_config() const {
    return _config_data;
}
