/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:35:42 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/27 14:27:37 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

#define DATA_FILE "data.csv"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Usage: ./program <filename>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadDatabase(DATA_FILE)) {
        std::cerr << "Error: Failed to load database from " << DATA_FILE << std::endl;
        return 1;
    }
    if (!btc.processInput(av[1])) {
        std::cerr << "Error: Failed to process input file: " << av[1] << std::endl;
        return 1;
    }

    return 0;
}
