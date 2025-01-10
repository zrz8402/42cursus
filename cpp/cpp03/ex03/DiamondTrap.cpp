/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:14:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 18:15:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

// ClapTrap hp(10) ep(10) damage(0)
// Scavtrap hp(100) ep(50) damage(20)
// Fraptrap hp(100) ep(100) damage(30)
// Fraptrap hp(100) ep(50) damage(30)
DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"){
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap parametric constructor was called." << std::endl;
	std::cout << name 
			<< std::setw(7) << "hp: " << hitPoints
			<< std::setw(7) << "ep: " << energyPoints
			<< std::setw(10) << "damage: " << attackDamage
			<< std::endl;		
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor was called." << std::endl;
}