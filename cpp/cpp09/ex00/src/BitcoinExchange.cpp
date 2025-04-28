/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:35:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/27 14:39:09 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
    data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) {
        std::cerr << "Error: invalid date length, must be in the format (YYYY-MM-DD)." << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: invalid date format, must be in the format (YYYY-MM-DD)." << std::endl;
        return false;
    }
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!std::isdigit(date[i])) {
            std::cerr << "Error: invalid character in date, must contain only digits (YYYY-MM-DD)." << std::endl;
            return false;
        }
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 5).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) {
        std::cerr << "Error: invalid month, must be between 01 and 12." << std::endl;
        return false;
    }

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    if (day < 1 || day > daysInMonth[month - 1]) {
        std::cerr << "Error: invalid day for the given month." << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    std::istringstream iss(valueStr);
    double tmp_value;

    // add check extra 
    if (!(iss >> tmp_value)) {
        std::cerr << "Error: non-numeric value." << std::endl;
        return false;
    }
    if (tmp_value < 0.0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (tmp_value > std::numeric_limits<int>::max()) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    value = static_cast<float>(tmp_value);
    return true;
}

void BitcoinExchange::trim(std::string& str) const {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos) {
        str = "";
    } else {
        str = str.substr(start, end - start + 1);
    }
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = data.lower_bound(date);
    if (it != data.end() && it->first == date) {
        return it->second;
    }
    if (it == data.begin()) {
        return 0.0f;
    }
    --it;
    return it->second;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: could not open database file: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::getline(infile, line); // skip header
    while (std::getline(infile, line)) {
        if (line.empty()) {
            continue;
        }

        size_t delim = line.find(',');
        if (delim == std::string::npos) {
            continue;
        }

        std::string date = line.substr(0, delim);
        std::string rateStr = line.substr(delim + 1);

        trim(date);
        trim(rateStr);

        std::istringstream iss(rateStr);
        float rate;
        if (!(iss >> rate)) {
            continue;
        }
    
        data[date] = rate;
    }
    infile.close();
    return true;
}

bool BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: could not open input file: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::getline(infile, line); // skip header
    while (std::getline(infile, line)) {
        if (line.empty()) {
            continue;
        }

        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delim);
        std::string valueStr = line.substr(delim + 1);

        trim(date);
        trim(valueStr);

        float value;
        if (!isValidDate(date)) {
            continue;
        }
        if (!isValidValue(valueStr, value)) {
            continue;
        }

        float rate = getRate(date);
        if (rate < 0.0f) {
            continue;
        }
    
        float   result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    infile.close();
    return true;
}