/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:00 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 12:17:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook	phoneBook;
	std::string cmd;

    std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
    std::getline(std::cin, cmd);
    while (cmd != "EXIT") {
        if (cmd == "ADD") {
            phoneBook.add();
        } else if (cmd == "SEARCH") {
            phoneBook.search();
        } else {
            std::cout << "Not a valid command\n";
            break;
        }
        std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);  
    }
    return (0);
}
