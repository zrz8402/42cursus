/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 16:07:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap was created" << std::endl;
	hp = 100;
	ep = 100;
	damage = 30;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other) {
	*this = other;
}

FragTrap& FragTrap::operator=( const FragTrap &other ) {
	if (this != &other) {
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->damage = other.damage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap was destroyed" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << name << ", do you wanna high-five?" << std::endl;
}