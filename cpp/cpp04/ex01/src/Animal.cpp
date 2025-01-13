/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:33:03 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 15:26:43 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Animal") {
	std::cout << "Animal default constructor was called." << std::endl;
}

Animal::Animal( std::string type ) : type(type) {
	std::cout << "Animal parametric constructor was called." << std::endl;
}

Animal::Animal( const Animal &other ) : type(other.type) {
	std::cout << "Animal copy constructor was called." << std::endl;
}

Animal& Animal::operator=( const Animal &other ) {
	if (this != &other) {
		std::cout << "Animal assignment operator was called." << std::endl;
		type = other.type;
	}
	return *this;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor was called." << std::endl;
}

std::string	Animal::getType( void ) const {
	return type;
}

void	Animal::makeSound( void ) const {
	std::cout << "Animal makes a sound." << std::endl;
}