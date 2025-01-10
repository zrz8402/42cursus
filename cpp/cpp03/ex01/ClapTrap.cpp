/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:38:40 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 15:30:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : name(name), hp(10), ep(10), damage(0) {
	std::cout << "ClapTrap was created" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) : name(other.name), hp(other.hp), ep(other.ep), damage(other.damage) {}

ClapTrap& ClapTrap::operator=( const ClapTrap &other ) {
	if (this != &other) {
		name = other.name;
		hp = other.hp;
		ep = other.ep;
		damage = other.damage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap was detroyed" << std::endl;
}

void	ClapTrap::setName( const std::string name ) {
	this->name = name;
}

void	ClapTrap::setHp( const unsigned int hp ) {
	this->hp = hp;
}

void	ClapTrap::setEp( const unsigned int ep ) {
	this->ep = ep;
}

void	ClapTrap::setDamage( const unsigned int damage ) {
	this->damage = damage;
}

std::string		ClapTrap::getName() const {
	return name;
}

unsigned int	ClapTrap::getHp() const {
	return hp;
}

unsigned int	ClapTrap::getEp() const {
	return ep;
}

unsigned int	ClapTrap::getDamage() const {
	return damage;	
}

void	ClapTrap::attack( const std::string& target ) {
	if (ep > 0 && hp > 0) {
		ep--;
		std::cout << "ClapTrap " << name << " attacks " << target
				<< ", causing " << damage << " points of damage!" 
				<< std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " doesn't have enough energy/hit points to attack." << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (hp > amount)
		hp -= amount;
	else
		hp = 0;
	std::cout << name << " takes " << amount << " points of damage(loses " 
				<< amount << " hit points)." << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (ep < 1)
		std::cout << name << " doesn't have enough energy points to repair." << std::endl;
	else {
		hp += amount;
		ep--;
		std::cout << name << " is repaired and gains " << amount << " hits points." << std::endl;
	}
}
