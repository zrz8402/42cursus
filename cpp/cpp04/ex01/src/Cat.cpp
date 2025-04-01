/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 16:49:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << GREEN << "Cat default constructor was called." << RESET << std::endl;
	brain = new Brain();
}

Cat::Cat( const Cat &other ) : Animal(other.type) {
	std::cout << GREEN << "Cat copy constructor was called." << RESET << std::endl;
	if (other.brain) {
		brain = new Brain(*other.brain);
	} else {
		brain = NULL;
	}
}

Cat& Cat::operator=( const Cat &other ) {
	if (this != &other) {
		std::cout << GREEN << "Cat assignment operator was called." << RESET << std::endl;

		Animal::operator=(other);
		
		delete brain;

		if (other.brain) {
			brain = new Brain(*other.brain);
		} else {
			brain = NULL;
		}
	}
	return *this;
}
	
Cat::~Cat( void ) {
	std::cout << GREEN << "Cat destructor was called." << RESET << std::endl;
	delete brain;
}

void	Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat says: Meow meow!" << RESET << std::endl;
}
