/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:33:03 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 17:31:42 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("AAnimal") {
	std::cout << YELLOW << "AAnimal default constructor was called." << RESET << std::endl;
}

AAnimal::AAnimal( std::string type ) : type(type) {
	std::cout << YELLOW << "AAnimal parametric constructor was called." << RESET << std::endl;
}

AAnimal::AAnimal( const AAnimal &other ) : type(other.type) {
	std::cout << YELLOW << "AAnimal copy constructor was called." << RESET << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal &other ) {
	if (this != &other) {
		std::cout << YELLOW << "AAnimal assignment operator was called." << RESET << std::endl;
		type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal( void ) {
	std::cout << YELLOW << "AAnimal destructor was called." << RESET << std::endl;
}

std::string	AAnimal::getType( void ) const {
	return type;
}
