/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:13:11 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 15:45:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog default constructor was called." << std::endl;
	brain = new Brain();
}

Dog::Dog( const Dog &other ) : Animal(other.type) {
	std::cout << "Dog copy constructor was called." << std::endl;
	if (other.brain) {
		brain = new Brain(*other.brain);
	} else {
		brain = NULL;
	}
}

Dog& Dog::operator=( const Dog &other ) {
	if (this != &other) {
		std::cout << "Dog assignment operator was called." << std::endl;

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
	std::cout << "Dog destructor was called." << std::endl;
	delete brain;
}
void	Dog::makeSound( void ) const {
	std::cout << "Dog barks: Woofffff!" << std::endl;
}
	