/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:07:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:43:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {}

Character::Character( const Character &other) {}

Character& Character::operator=( const Character &other ) {
	if (this != &other) {
	}
	return *this;
}

Character::~Character( void ) {}

std::string const & Character::getName( void ) const {
	return name;
}

void	Character::equip( AMateria* m ) {
	
}

void	Character::unequip( int idx ) {
	
}

void	Character::use( int idx, Character& target ) {
	
}
