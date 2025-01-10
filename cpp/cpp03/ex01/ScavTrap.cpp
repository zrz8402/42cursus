/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 15:30:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap was created" << std::endl;
	hp = 100;
	ep = 50;
	damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
	*this = other;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
	if (this != &other) {
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->damage = other.damage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap was destroyed" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (ep > 0 && hp > 0) {
		ep--;
		std::cout << "ScavTrap " << name << " attacks " << target
				<< ", causing " << damage << " points of damage!" 
				<< std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " doesn't have enough energy/hit points to attack." << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}