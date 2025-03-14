/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:45:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 12:25:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

void	Weapon::setType(const std::string &type) {
	this->type = type;
}

// const std::string & => Return Type
// Weapon::getType() const
//		=> is a const member function
//		=> does not modify any non-mutable data members of the class
const std::string	&Weapon::getType() const{
	return type;
}