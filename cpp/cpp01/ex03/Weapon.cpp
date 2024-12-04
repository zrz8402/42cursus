/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:45:05 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 14:49:05 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	
}

Weapon::~Weapon() {
	
}

void	Weapon::setType(std::string newType) {
	type = newType;
}

std::string	Weapon::getType() {
	return type;
}