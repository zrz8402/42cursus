/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:51 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 11:31:27 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << BLUE << "Dog default constructor was called." << RESET << std::endl;
}

Dog::Dog( const Dog &other ) : Animal(other.type) {
	std::cout << BLUE << "Dog copy constructor was called." << RESET << std::endl;
}

Dog& Dog::operator=( const Dog &other ) {
	if (this != &other) {
		std::cout << BLUE << "Dog assignment operator was called." << RESET << std::endl;
		// ensure that the base class’s state is properly copied
		Animal::operator=(other);
	}
	return *this;
}
	
Dog::~Dog( void ) {
	std::cout << BLUE << "Dog destructor was called." << RESET << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << BLUE << "Dog says: mow!" << RESET << std::endl;
}
