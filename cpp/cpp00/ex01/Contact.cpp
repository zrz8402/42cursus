/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:24:42 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/01 13:07:27 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	
}

Contact::~Contact(){
	
}

void   Contact::setFirstName(const std::string& newFirstName) {
    firstName = newFirstName;
}

void   Contact::setLastName(const std::string& newLastName) {
    lastName = newLastName;
}

void   Contact::setNickname(const std::string& newNickname) {
    nickname = newNickname;
}

void   Contact::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void   Contact::setDarkestSecret(const std::string& newDarkestSecret) {
    darkestSecret = newDarkestSecret;
}

std::string   Contact::getFirstName() const {
    return firstName;
}

std::string   Contact::getLastName() const {
    return lastName;
}

std::string   Contact::getNickname() const {
    return nickname;
}

std::string   Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string   Contact::getDarkestSecret() const {
    return darkestSecret;
}