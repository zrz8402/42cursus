/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/12 19:02:58 by ruzhang          ###   ########.fr       */
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

std::string	getInput()
{
	std::string	input;

	while (true) {

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
	std::cout << "Enter first name: ";
	std::string firstName = getInput();
	contacts[index].setFirstName(firstName);

	std::cout << "Enter last name: ";
	std::string lastName = getInput();
	contacts[index].setLastName(lastName);

	std::cout << "Enter nickname: ";
	std::string nickname = getInput();
	contacts[index].setNickname(nickname);

	std::cout << "Enter phone number: ";
	std::string phoneNumber = getInput();
	contacts[index].setPhoneNumber(phoneNumber);

	std::cout << "Enter darkest secret: ";
	std::string darkestSecret = getInput();
	contacts[index].setDarkestSecret(darkestSecret);

	if (size < 8)
		size++;
	index = (index + 1) % 8;
}

// std::string	getInput(const std::string &prompt)
// {
// 	std::string	input;

// 	while (true) {
// 		std::cout << prompt;

// 		if (!std::getline(std::cin, input)) {
// 			if(std::cin.eof()) {
// 				return "";
// 			}
// 		}

// 		if (!input.empty()) {
// 			return input;
// 		} else {
// 			std::cout << "Input cannot be empty. Please try again." << std::endl;
// 		}
// 	}
// }

// void	PhoneBook::add()
// {
// 	std::string firstName = getInput("Enter first name: ");
// 	if (firstName.empty())
// 		exit(0);
// 	contacts[index].setFirstName(firstName);

// 	std::string lastName = getInput("Enter last name: ");
// 	if (lastName.empty())
// 		exit(0);
// 	contacts[index].setLastName(lastName);

// 	std::string nickname = getInput("Enter nickname: ");
// 	if (nickname.empty())
// 		exit(0);
// 	contacts[index].setNickname(nickname);

// 	std::string phoneNumber = getInput("Enter phone number: ");
// 	if (phoneNumber.empty())
// 		exit(0);
// 	contacts[index].setPhoneNumber(phoneNumber);

// 	std::string darkestSecret = getInput("Enter darkest secret: ");
// 	if (darkestSecret.empty())
// 		exit(0);
// 	contacts[index].setDarkestSecret(darkestSecret);

// 	if (size < 8)
// 		size++;
// 	index = (index + 1) % 8;
// }

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
