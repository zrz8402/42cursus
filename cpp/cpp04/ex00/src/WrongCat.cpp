/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:51 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 16:30:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << RED << "WrongCat default constructor was called." << RESET << std::endl;
}

WrongCat::WrongCat( std::string type ) : WrongAnimal(type) {
	std::cout << RED << "WrongCat parametric constructor was called." << RESET << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other.type) {
	std::cout << RED << "WrongCat copy constructor was called." << RESET << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat &other ) {
	if (this != &other) {
		std::cout << RED << "WrongCat assignment operator was called." << RESET << std::endl;
		WrongAnimal::operator=(other);
	}
	return *this;
}
	
WrongCat::~WrongCat( void ) {
	std::cout << RED << "WrongCat destructor was called." << RESET << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << RED << "WrongCat says: mow!" << RESET << std::endl;
}
