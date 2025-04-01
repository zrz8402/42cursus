/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:08:02 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:42:08 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : type("cure") {}

Cure::Cure( const Cure &other) : type(other.type) {}

Cure& Cure::operator=( const Cure &other ) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Cure::~Cure( void ) {}

std::string const & Cure::getType( void ) const {
	return type;
}

Cure*	Cure::clone( void ) const {
	return new Cure(*this);
}

// Display: "* heals <name>’s wounds *"
void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
