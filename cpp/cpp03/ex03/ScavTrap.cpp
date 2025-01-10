/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 18:06:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	std::cout << "ScavTrap default constructor was called." << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap parametric was called." << std::endl;
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
	std::cout << "ScavTrap destructor was called." << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << "ScavTrap " << name << " doesn't have enough energy/hit points to attack." << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target
				<< ", causing " << attackDamage << " points of damage!" 
				<< std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}