/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:09:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Cat default constructor was called." << std::endl;
	brain = new Brain();
}

Cat::Cat( const Cat &other ) : Animal(other.type) {
	std::cout << "Cat copy constructor was called." << std::endl;
	if (other.brain) {
		brain = new Brain(*other.brain);
	} else {
		brain = NULL;
	}
}

Cat& Cat::operator=( const Cat &other ) {
	if (this != &other) {
		std::cout << "Cat assignment operator was called." << std::endl;

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
	std::cout << "Cat destructor was called." << std::endl;
	delete brain;
}

void	Cat::makeSound( void ) const {
	std::cout << "Cat says: Meow meow!" << std::endl;
}