/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:08:02 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 11:20:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( const Cure &other) : AMateria(other.type) {}

Cure& Cure::operator=( const Cure &other ) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Cure::~Cure( void ) {}

Cure*	Cure::clone( void ) const {
	return new Cure(*this);
}

// Display: "* heals <name>’s wounds *"
void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
