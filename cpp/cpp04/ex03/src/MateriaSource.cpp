/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:08:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:30:55 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {}

MateriaSource::MateriaSource( const MateriaSource &other) {}

MateriaSource& MateriaSource::operator=( const MateriaSource &other ) {
	if (this != &other) {
		
	}
	return *this;
}

MateriaSource::~MateriaSource( void ) {}

/*
Copies the Materia passed as a parameter and stores it in memory 
so it can be cloned later. 
Like the Character, the MateriaSource can know at most 4 Materias.
They are not necessarily unique.
*/
void	MateriaSource::learnMateria( AMateria* ) {
	
}

/*
Returns a new Materia.
The latter is a copy of the Materia previously learned by the MateriaSource
whose type equals the one passed as parameter.
Returns 0 if the type is unknown.
*/
AMateria*	MateriaSource::createMateria( std::string const & type ) {
	
}
