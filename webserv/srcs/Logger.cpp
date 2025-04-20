#include "Logger.hpp"

void Logger::info(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}

void Logger::error(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}

void Logger::warning(const std::string& message) {
    std::cout << "[WARNING] " << message << std::endl;
}

void Logger::request(const std::string& message) {
    std::cout << "[REQUEST] " << message << std::endl;
}

void Logger::response(const std::string& message) {
    std::cout << "[RESPONSE] " << message << std::endl;
}

void Logger::debug(const std::string& message) {
    std::cout << "[DEBUG] " << message << std::endl;
}
