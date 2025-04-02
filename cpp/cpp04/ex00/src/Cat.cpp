/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:36:27 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 11:54:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << GREEN << "Cat default constructor was called." << RESET << std::endl;
}

Cat::Cat( const Cat &other ) : Animal(other.type) {
	std::cout << GREEN << "Cat copy constructor was called." << RESET << std::endl;
}

Cat& Cat::operator=( const Cat &other ) {
	if (this != &other) {
		std::cout << GREEN << "Cat assignment operator was called." << RESET << std::endl;
		Animal::operator=(other);
	}
	return *this;
}
	
Cat::~Cat( void ) {
	std::cout << GREEN << "Cat destructor was called." << RESET << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat says: mow!" << RESET << std::endl;
}
