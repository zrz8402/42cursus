#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <sstream>
#include <iostream>

#include "constants.hpp"

class Logger {

    public:

        static void info(std::string message);
        static void error(std::string message);
        static void warning(std::string message);
        static void request(std::string message);
        static void response(std::string message);
        static void debug(std::string message);

};

template <typename T>
std::string to_string(const T &value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif
