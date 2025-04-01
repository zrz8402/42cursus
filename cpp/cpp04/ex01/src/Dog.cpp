/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:13:11 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 16:49:42 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << BLUE << "Dog default constructor was called." << RESET << std::endl;
	brain = new Brain();
}

Dog::Dog( const Dog &other ) : Animal(other.type) {
	std::cout << BLUE << "Dog copy constructor was called." << RESET << std::endl;
	if (other.brain) {
		brain = new Brain(*other.brain);
	} else {
		brain = NULL;
	}
}

Dog& Dog::operator=( const Dog &other ) {
	if (this != &other) {
		std::cout << BLUE << "Dog assignment operator was called." << RESET << std::endl;

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
	
Dog::~Dog( void ) {
	std::cout << BLUE << "Dog destructor was called." << RESET << std::endl;
	delete brain;
}

void	Dog::makeSound( void ) const {
	std::cout << BLUE << "Dog barks: Woofffff!" << RESET << std::endl;
}
	