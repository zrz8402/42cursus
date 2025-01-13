/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:13:11 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:10:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog") {
	std::cout << "Dog default constructor was called." << std::endl;
	brain = new Brain();
}

Dog::Dog( const Dog &other ) : AAnimal(other.type) {
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

		AAnimal::operator=(other);
		
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
	