/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:51 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 15:27:00 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor was called." << std::endl;
}

WrongCat::WrongCat( std::string type ) : WrongAnimal(type) {
	std::cout << "WrongCat parametric constructor was called." << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other.type) {
	std::cout << "WrongCat copy constructor was called." << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat &other ) {
	if (this != &other) {
		std::cout << "WrongCat assignment operator was called." << std::endl;
		WrongAnimal::operator=(other);
	}
	return *this;
}
	
WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor was called." << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "WrongCat says: mow!" << std::endl;
}