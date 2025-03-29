/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/29 14:36:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(){
	size = 0;
	index = 0;
}

PhoneBook::~PhoneBook(){
	
}

std::string	getInput(const std::string& prompt)
{
	std::string	input;

	while (true) {
		std::cout << prompt;

		if (!std::getline(std::cin, input)) {
			exit(0);
		}

		if (!input.empty()) {
			return input;
		} else {
			std::cout << "Input cannot be empty. Please try again." << std::endl;
		}
	}
}

void	PhoneBook::add()
{
	std::string firstName = getInput("Enter first name: ");
	contacts[index].setFirstName(firstName);

	std::string lastName = getInput("Enter last name: ");
	contacts[index].setLastName(lastName);

	std::string nickname = getInput("Enter nickname: ");
	contacts[index].setNickname(nickname);

	std::string phoneNumber = getInput("Enter phone number: ");
	contacts[index].setPhoneNumber(phoneNumber);

	std::string darkestSecret = getInput("Enter darkest secret: ");
	contacts[index].setDarkestSecret(darkestSecret);

	if (size < 8)
		size++;
	index = (index + 1) % 8;
}

bool	validEntry(std::string entry, int limit)
{
	if (entry.length() == 1){
		if (entry[0] >= '0' && entry[0] <= (limit + '0'))
			return true;
	}
	return false;
}

void	displayHeader(void)
{
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << "\n";
}

void	displayField(const std::string& field, std::string::size_type width, std::string end)
{
	if (field.length() > width)
		std::cout << std::right << field.substr(0, 9) << "." << end;
	else
		std::cout << std::setw(10) << std::right << field << end;
}

void	PhoneBook::displayContact(int i)
{
	std::cout << std::setw(10) << std::right << i << "|";
	displayField(contacts[i].getFirstName(), 10, "|");
	displayField(contacts[i].getLastName(), 10, "|");
	displayField(contacts[i].getNickname(), 10, "\n");
}

void	PhoneBook::search()
{
	std::string entry;
	int		 	maxEntry = size - 1;

	if (maxEntry < 0) {
		std::cout << "Empty phonebook. Add some contacts first." << std::endl;
		return ;
	}

	displayHeader();
	for (int i = 0; i < size; i++) {
			displayContact(i);
	}

	while (true) {
		std::cout << "Enter the entry index(0 - " << maxEntry << "): ";
		if (!std::getline(std::cin, entry)) {
			exit(0);
		}
		if (!validEntry(entry, maxEntry)) {
			std::cout << "Invalid entry. Please try again." << std::endl;
		} else {
			displayHeader();
			displayContact(entry[0] - '0');
			break;
		}
	}

}
