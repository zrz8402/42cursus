/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:38:40 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/12 10:29:28 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void )  : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor was called." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap parametric constructor was called." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {}

ClapTrap& ClapTrap::operator=( const ClapTrap &other ) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor was called." << std::endl;
}

void	ClapTrap::setName( const std::string name ) {
	this->name = name;
}

void	ClapTrap::setHitPoints( const unsigned int hitPoints ) {
	this->hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints( const unsigned int energyPoints ) {
	this->energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage( const unsigned int attackDamage ) {
	this->attackDamage = attackDamage;
}

std::string		ClapTrap::getName( void ) const {
	return name;
}

unsigned int	ClapTrap::getHitPoints( void ) const {
	return hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {
	return energyPoints;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {
	return attackDamage;	
}

// attack: ep -= 1; target_hp -= damage
void	ClapTrap::attack( const std::string& target ) {
	if (energyPoints <= 0 || hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " doesn't have enough energy/hit points to attack." << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target
				<< ", causing " << attackDamage << " points of damage!" 
				<< std::endl;
}

// takeDamage: hp -= amount (being attacked)
void	ClapTrap::takeDamage( unsigned int amount ) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " doesn't have enough hit points left" << std::endl;
		return ;
	}

	if (hitPoints > amount)
		hitPoints -= amount;
	else
		hitPoints = 0;

	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage." << std::endl;
}

// beRepaired: ep -= 1; hp += amount
void	ClapTrap::beRepaired( unsigned int amount ) {
	if (energyPoints <= 0 || hitPoints <= 0)
		std::cout << "ClapTrap " << name << " doesn't have enough energy/hit points to repair." << std::endl;
	else {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " is repaired and gains " << amount << " hits points." << std::endl;
	}
}
