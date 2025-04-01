/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:02:21 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 16:30:11 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") {
	std::cout << RED << "WrongAnimal default constructor was called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type(type) {
	std::cout << RED << "WrongAnimal parametric constructor was called." << RESET << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ) : type(other.type) {
	std::cout << RED << "WrongAnimal copy constructor was called." << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &other ) {
	if (this != &other) {
		std::cout << RED << "WrongAnimal assignment operator was called." << RESET << std::endl;
		type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << RED << "WrongAnimal destructor was called." << RESET << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << RED << "WrongAnimal makes a ding~ sound." << RESET << std::endl;
}
