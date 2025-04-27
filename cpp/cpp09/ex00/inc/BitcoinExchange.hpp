/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:35:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/27 14:32:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>

#define MAX_VALID_INPUT = 1000000.0f

class BitcoinExchange {

private:
    std::map<std::string, float> _data;

    bool isLeapYear(int year) const;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
    void trim(std::string& str) const;
    float getRate(const std::string& date) const;
    
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange& operator=(BitcoinExchange const &other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);
    bool processInput(const std::string& filename) const;

};

#endif