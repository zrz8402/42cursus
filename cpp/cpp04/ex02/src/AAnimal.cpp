/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:33:03 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:13:43 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("AAnimal") {
	std::cout << "AAnimal default constructor was called." << std::endl;
}

AAnimal::AAnimal( std::string type ) : type(type) {
	std::cout << "AAnimal parametric constructor was called." << std::endl;
}

AAnimal::AAnimal( const AAnimal &other ) : type(other.type) {
	std::cout << "AAnimal copy constructor was called." << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal &other ) {
	if (this != &other) {
		std::cout << "AAnimal assignment operator was called." << std::endl;
		type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor was called." << std::endl;
}

std::string	AAnimal::getType( void ) const {
	return type;
}

void	AAnimal::makeSound( void ) const {
	std::cout << "Animal makes no sound." << std::endl;
}