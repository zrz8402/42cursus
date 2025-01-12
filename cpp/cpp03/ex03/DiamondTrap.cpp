/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:14:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/12 11:19:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

DiamondTrap::DiamondTrap( void ) : name("Unnamed") {
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap default constructor was called." << std::endl;
}

// ClapTrap hp(10) ep(10) damage(0)
// Scavtrap hp(100) ep(50) damage(20)
// Fraptrap hp(100) ep(100) damage(30)
// FragTrap::hitPoints; ScavTrap::energyPoints; FragTrap::attackDamage;
// Diamondtrap hp(100) ep(50) damage(30)
DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
	// this->name = name;
	std::cout << "DiamondTrap parametric constructor was called." << std::endl;
	std::cout << name 
			<< std::setw(7) << "hp: " << hitPoints
			<< std::setw(7) << "ep: " << energyPoints
			<< std::setw(10) << "damage: " << attackDamage
			<< std::endl;		
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) {
	*this = other;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &other ) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor was called." << std::endl;
}

std::string		DiamondTrap::getName( void ) const {
	return name;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "Diamondtrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
