/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 16:47:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::string	colorizeFrag(const std::string& color, const std::string& str) {
	return color + str + RESET;
}

FragTrap::FragTrap( void ) {
	std::cout << colorizeFrag(BLUE, "FragTrap") << " default constructor was called." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << colorizeFrag(BLUE, "FragTrap") << " parametric constructor was called." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other) {
	*this = other;
}

FragTrap& FragTrap::operator=( const FragTrap &other ) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << colorizeFrag(BLUE, "FragTrap") << " destructor was called." << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << colorizeFrag(BLUE, "FragTrap ") << name << ", do you wanna high-five?" << std::endl;
}