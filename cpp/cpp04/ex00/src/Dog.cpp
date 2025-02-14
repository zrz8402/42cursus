/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:13:11 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 15:26:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Dog default constructor was called." << std::endl;
}

Dog::Dog( std::string type ) : Animal(type) {
	std::cout << "Dog parametric constructor was called." << std::endl;
}

Dog::Dog( const Dog &other ) : Animal(other.type) {
	std::cout << "Dog copy constructor was called." << std::endl;
}

Dog& Dog::operator=( const Dog &other ) {
	if (this != &other) {
		std::cout << "Dog assignment operator was called." << std::endl;
		Animal::operator=(other);
	}
	return *this;
}
	
Dog::~Dog( void ) {
	std::cout << "Dog destructor was called." << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Dog barks: Woofffff!" << std::endl;
}
	