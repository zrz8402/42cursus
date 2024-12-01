/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:05 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/01 13:10:32 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(){
	
}

PhoneBook::~PhoneBook(){
	
}

int PhoneBook::getSize()
{
    return size;
}

void    PhoneBook::saveContact(const Contact& newContact)
{
    if (size < 8) {
        phonebook[size++] = newContact;
    } else {
        phonebook[oldestContact] = newContact;
        oldestContact = (oldestContact + 1) % 8;
    }
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
    if (phonebook[i].getFirstName().size() > 10)
        std::cout << std::right << phonebook[i].getLastName().substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << std::right << phonebook[i].getLastName() << "|";
    if (phonebook[i].getFirstName().size() > 10)
        std::cout << std::right << phonebook[i].getNickname().substr(0, 9) << ".\n";
    else
        std::cout << std::setw(10) << std::right << phonebook[i].getNickname() << "\n";
}
