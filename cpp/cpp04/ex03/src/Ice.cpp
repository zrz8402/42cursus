/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:08:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 11:19:32 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice( const Ice &other) : AMateria(other) {}

Ice& Ice::operator=( const Ice &other ) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Ice::~Ice( void ) {}

Ice*	Ice::clone( void ) const {
	return new Ice(*this);
}

// Display: "* shoots an ice bolt at <name> *"
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
