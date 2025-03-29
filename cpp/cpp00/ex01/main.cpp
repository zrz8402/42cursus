/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/29 13:59:04 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string cmd;

	std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
	while (std::getline(std::cin, cmd)) {
		if (cmd == "EXIT") {
			break;
		}
		else if (cmd == "ADD") {
			phoneBook.add();
		} else if (cmd == "SEARCH") {
			phoneBook.search();
		} else {
			std::cout << "Not a valid command\n";
		}
		std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
	}
	return (0);
}
