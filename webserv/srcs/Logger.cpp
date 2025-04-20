#include "Logger.hpp"

void Logger::info(std::string message) {
    std::cout << "[" << GREEN << "INFO" << RESET << "] " << message << std::endl;
}

void Logger::error(std::string message) {
    std::cerr << "[" << RED << "ERROR" << RESET << "] " << message << std::endl;
}

void Logger::warning(std::string message) {
    std::cout << "[" << YELLOW << "WARNING" << RESET << "] " << message << std::endl;
}

void Logger::request(std::string message) {
    std::cout << "[" << BLUE << "REQUEST" << RESET << "] " << message << std::endl;
}

void Logger::response(std::string message) {
    std::cout << "[" << PURPLE << "RESPONSE" << RESET << "] " << message << std::endl;
}

#ifdef DEBUG
    void Logger::debug(std::string message) {
        std::cout << "[" << CYAN << "DEBUG" << RESET << "] " << message << std::endl;
    }
#else
    void Logger::debug(std::string message) {
        (void) message;
    }
#endif
