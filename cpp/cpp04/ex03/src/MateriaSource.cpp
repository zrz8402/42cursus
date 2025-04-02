/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:08:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 15:43:52 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	for (int i = 0; i < slots; i++) {
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource &other) {
	*this = other;
}

MateriaSource& MateriaSource::operator=( const MateriaSource &other ) {
	if (this != &other) {
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

MateriaSource::~MateriaSource( void ) {
	for (int i = 0; i < slots; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
	}
}

/*
Copies the Materia passed as a parameter and stores it in memory 
so it can be cloned later. 
Like the Character, the MateriaSource can know at most 4 Materias.
They are not necessarily unique.
*/
void	MateriaSource::learnMateria( AMateria* materia ) {
	for (int i = 0; i < slots; i++) {
		if (!inventory[i]) {
			std::cout << "Learning materia " << GREEN << materia->getType() << RESET << std::endl;
			inventory[i] = materia;
			return ;
		}
	}
	std::cout << RED << "MateriaSource inventory is full. Materia " << materia->getType() << " cannot be added and will be deleted." << RESET << std::endl;
	delete materia;
}

/*
Returns a new Materia.
The latter is a copy of the Materia previously learned by the MateriaSource
whose type equals the one passed as parameter.
Returns 0 if the type is unknown.
*/
AMateria*	MateriaSource::createMateria( std::string const & type ) {	
	for (int i = 0; i < slots; i++) {
		if (inventory[i] && inventory[i]->getType() == type) {
			std::cout << "Materia " << GREEN << type << RESET << " is created." << std::endl;
			return inventory[i]->clone();
		}
	}
	std::cout << RED << "Materia " << type << " cannot be found. Learn it first." << RESET << std::endl;
	return NULL;
}
