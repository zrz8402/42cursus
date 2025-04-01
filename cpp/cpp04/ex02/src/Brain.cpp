/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:18:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 17:33:30 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << MAGENTA << "Brain default constructor was called." << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}

Brain::Brain( const std::string ideas[100] ) {
	std::cout << MAGENTA << "Brain parametric constructor was called." << RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ideas[i];
	}
}

Brain::Brain( const Brain &other ) {
	std::cout << MAGENTA << "Brain copy constructor was called." << RESET << std::endl;
	*this = other;
}

Brain& Brain::operator=( const Brain &other ) {
	std::cout << MAGENTA << "Brain assignment operator was called." << RESET << std::endl;
	if (this != &other){
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain( void ) {
	std::cout << MAGENTA << "Brain destructor was called." << RESET << std::endl;
}

void	Brain::setIdea( int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	} else {
		std::cerr << RED << "Index is out of bounds." << RESET << std::endl;
	}
}

void	Brain::setIdeas( const std::string (&ideas)[100] ) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ideas[i];
	}
}

std::string	Brain::getIdea( int index ) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	} else {
		std::cerr << RED << "Index is out of bounds." << RESET << std::endl;
		return "";
	}
}

const std::string*	Brain::getIdeas( void ) const {
	return ideas;
}
