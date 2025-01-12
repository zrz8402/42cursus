/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:29 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/12 11:19:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iomanip>
#include <iostream>

void	print_status(DiamondTrap &name) {
	std::cout << "Current status:" << std::endl;
	std::cout << name.getName()
				<< std::setw(7) << "hp: " << name.getHitPoints()
				<< std::setw(7) << "ep: " << name.getEnergyPoints()
				<< std::setw(10) << "damage: " << name.getAttackDamage()
				<< std::endl;	
}

int main() {
	DiamondTrap	rocket("Rocket");

	print_status(rocket);

	std::cout << "----Who Am I----" << std::endl;
	rocket.whoAmI();

	return 0;
}