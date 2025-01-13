/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:17:45 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 18:37:28 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria( void ) : type("Default") {}

AMateria::AMateria( const std::string & type ) : type(type) {}

AMateria::AMateria( const AMateria &other) : type(other.type) {}

AMateria& AMateria::operator=( const AMateria &other ) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

AMateria::~AMateria( void ) {}

std::string const & AMateria::getType( void ) const {
	return type;
}

void	AMateria::use(ICharacter& target) {
	
}
