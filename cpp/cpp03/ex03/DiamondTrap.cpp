/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:14:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/31 13:55:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

std::string	colorizeDiamond(const std::string& color, const std::string& str) {
	return color + str + RESET;
}

DiamondTrap::DiamondTrap( void ) : name("Unnamed") {
	ClapTrap::name = name + "_clap_name";
	std::cout << colorizeDiamond(BLUE, "DiamondTrap") << " default constructor was called." << std::endl;
}

/*
ClapTrap hp(10) ep(10) damage(0)
Scavtrap hp(100) ep(50) damage(20)
Fraptrap hp(100) ep(100) damage(30)
FragTrap::hitPoints; ScavTrap::energyPoints; FragTrap::attackDamage;
Diamondtrap hp(100) ep(50) damage(30)
*/
DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
	this->name = name;
	std::cout << colorizeDiamond(BLUE, "DiamondTrap") << " parametric constructor was called." << std::endl;
	// std::cout << name 
	// 		<< std::setw(7) << "hp: " << hitPoints
	// 		<< std::setw(7) << "ep: " << energyPoints
	// 		<< std::setw(10) << "damage: " << attackDamage
	// 		<< std::endl;
}
/*
Doesn't work if I set all values bot in Scav and Frag
The values will be overritten by the order of inheritance
hitPoints = FragTrap::hitPoints;
energyPoints = ScavTrap::energyPoints;
attackDamage = FragTrap::attackDamage;
*/

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
	std::cout << colorizeDiamond(BLUE, "DiamondTrap") << " destructor was called." << std::endl;
}

std::string		DiamondTrap::getName( void ) const {
	return name;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "Diamondtrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
