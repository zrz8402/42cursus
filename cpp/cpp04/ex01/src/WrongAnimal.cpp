/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:02:21 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 15:26:57 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor was called." << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type(type) {
	std::cout << "WrongAnimal parametric constructor was called." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ) : type(other.type) {
	std::cout << "WrongAnimal copy constructor was called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &other ) {
	if (this != &other) {
		std::cout << "WrongAnimal assignment operator was called." << std::endl;
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor was called." << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "WrongAnimal makes a sound." << std::endl;
}