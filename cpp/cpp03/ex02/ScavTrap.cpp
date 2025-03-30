/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 16:31:57 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::string	colorizeScav(const std::string& color, const std::string& str) {
	return color + str + RESET;
}

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << colorizeScav(BLUE, "ScavTrap") << " default constructor was called." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << colorizeScav(BLUE, "ScavTrap") << " parametric constructor was called." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
	*this = other;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << colorizeScav(BLUE, "ScavTrap") << " destructor was called." << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << colorizeScav(BLUE, "ScavTrap ") << RED << name << " doesn't have enough energy/hit points to attack." << RESET << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << colorizeScav(BLUE, "ScavTrap ") << name << " attacks " << target
				<< ", causing " << attackDamage << " points of damage!" 
				<< std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << colorizeScav(BLUE, "ScavTrap ") << name << " is now in Gate keeper mode." << std::endl;
}
