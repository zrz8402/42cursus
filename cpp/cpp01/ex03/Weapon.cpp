/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:45:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 09:51:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

void	Weapon::setType(const std::string &type) {
	this->type = type;
}

/*
const std::string & => Return Type
Avoiding Copies:
If return `std::string`, the function would have to copy the string before returning it
while return `reference (const std::string&)`, avoid unnecessary copies
Immutability:
With `const std::string&`, the caller cannot accidentally
modify the type of the weapon directly through this reference.

Weapon::getType() const
		=> is a const member function
		=> does not modify any non-mutable data members of the class
*/
const std::string	&Weapon::getType() const{
	return type;
}
