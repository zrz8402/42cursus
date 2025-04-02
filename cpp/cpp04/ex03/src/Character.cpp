/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:07:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 16:01:30 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {
	for (int i = 0; i < slots; i++) {
		inventory[i] = NULL;
	}
}

Character::Character( const std::string &name ) : name(name) {
	for (int i = 0; i < slots; i++) {
		inventory[i] = NULL;
	}
}

Character::Character( const Character &other) {
	*this = other;
}

Character& Character::operator=( const Character &other ) {
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < slots; i++) {
			if (inventory[i]) {
				delete inventory[i];
			}
			if (other.inventory[i]) {
				this->inventory[i] = other.inventory[i]->clone();
			} else {
				this->inventory[i] = NULL;
			}
		}
	}
	return *this;
}

Character::~Character( void ) {
	for (int i = 0; i < slots; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
	}
}

std::string const & Character::getName( void ) const {
	return name;
}

void	Character::equip( AMateria* m ) {
	if (!m) {
		std::cout << RED << "No materia passed." << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < slots; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			std::cout << name << " equips " << GREEN << m->getType() << RESET
				<< " at slot " << GREEN << i << RESET << std::endl;
			return ;
		}
	}
	std::cout << RED << "Inventory is full. " << name << " cannot equip materia " << m->getType() << RESET << std::endl;
	delete m;
}

void	Character::unequip( int idx ) {
	if (idx >= 0 && idx <= slots && inventory[idx]) {
		std::cout << name << " unequips " << GREEN << inventory[idx]->getType() 
			<< RESET << " at slot " << GREEN << idx << RESET << std::endl;
		inventory[idx] = NULL;	
	} else {
		std::cout << RED << "No materia at current slot / Out of bounds." << RESET << std::endl;
	}
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx <= slots && inventory[idx]) {
		inventory[idx]->use(target);	
	} else {
		std::cout << RED << "No materia at current slot / Out of bounds." << RESET << std::endl;
	}
}
