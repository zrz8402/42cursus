/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:05 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 12:51:30 by ruzhang          ###   ########.fr       */
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

void	PhoneBook::add()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
    } while (firstName.empty());
    phonebook[index].setFirstName(firstName);

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
    } while (lastName.empty());
    phonebook[index].setLastName(lastName);

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
    } while (nickname.empty());
	phonebook[index].setNickname(nickname);

    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
    } while (phoneNumber.empty());
    phonebook[index].setPhoneNumber(phoneNumber);

    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkestSecret);
    } while (darkestSecret.empty());
    phonebook[index].setDarkestSecret(darkestSecret);
	if (size < 8)
		size++;
	index = (index + 1) % 8;
}

bool    validEntry(std::string entry, int limit)
{
    if (entry.length() == 1){
        if (entry[0] >= '0' && entry[0] <= (limit + '0'))
            return true;
    }
    return false;
}

void	PhoneBook::search()
{
    std::string index;
    int         maxEntry = size - 1;

    if (maxEntry < 0) {
        std::cout << "Empty phonebook. Add some contacts first." << std::endl;
        return ;
    }
    do {
        std::cout << "Enter the entry index(0 - " << maxEntry << "): ";
        std::getline(std::cin, index);
    } while (!validEntry(index, maxEntry));
    displayContact(index[0] - '0');
}

void    PhoneBook::displayContact(int i)
{
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "first name" << "|";
    std::cout << std::setw(10) << std::right << "last name" << "|";
    std::cout << std::setw(10) << std::right << "nickname" << "\n";

    std::cout << std::setw(10) << std::right << i << "|";
    if (phonebook[i].getFirstName().size() > 10)
        std::cout << std::right << phonebook[i].getFirstName().substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << std::right << phonebook[i].getFirstName() << "|";

    if (phonebook[i].getLastName().size() > 10)
        std::cout << std::right << phonebook[i].getLastName().substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << std::right << phonebook[i].getLastName() << "|";

    if (phonebook[i].getNickname().size() > 10)
        std::cout << std::right << phonebook[i].getNickname().substr(0, 9) << ".\n";
    else
        std::cout << std::setw(10) << std::right << phonebook[i].getNickname() << "\n";
}
