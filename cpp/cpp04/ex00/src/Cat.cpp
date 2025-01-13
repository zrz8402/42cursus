/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 12:28:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Cat default constructor was called." << std::endl;
}

Cat::Cat( std::string type ) : Animal(type) {
	std::cout << "Cat parametric constructor was called." << std::endl;
}

Cat::Cat( const Cat &other ) : Animal(other.type) {
	std::cout << "Cat copy constructor was called." << std::endl;
}

Cat& Cat::operator=( const Cat &other ) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Cat assignment operator was called." << std::endl;
	}
	return *this;
}
	
Cat::~Cat( void ) {
	std::cout << "Cat destructor was called." << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Cat says: Meow meow!" << std::endl;
}