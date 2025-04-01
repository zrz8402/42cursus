/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:33:03 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 17:14:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Animal") {
	std::cout << YELLOW << "Animal default constructor was called." << RESET << std::endl;
}

Animal::Animal( std::string type ) : type(type) {
	std::cout << YELLOW << "Animal parametric constructor was called." << RESET << std::endl;
}

Animal::Animal( const Animal &other ) : type(other.type) {
	std::cout << YELLOW << "Animal copy constructor was called." << RESET << std::endl;
}

Animal& Animal::operator=( const Animal &other ) {
	if (this != &other) {
		std::cout << YELLOW << "Animal assignment operator was called." << RESET << std::endl;
		type = other.type;
	}
	return *this;
}

Animal::~Animal( void ) {
	std::cout << YELLOW << "Animal destructor was called." << RESET << std::endl;
}

std::string	Animal::getType( void ) const {
	return type;
}

void	Animal::makeSound( void ) const {
	std::cout << YELLOW << "Animal makes a di~ sound." << RESET << std::endl;
}