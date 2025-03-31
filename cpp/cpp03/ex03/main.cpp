/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:29 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/31 13:56:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iomanip>
#include <iostream>

void	print_status(DiamondTrap &name) {
	std::cout << GREEN << "Current status:" << std::endl;
	std::cout << name.getName() 
				<< std::setw(7) << "hp: " << name.getHitPoints()
				<< std::setw(7) << "ep: " << name.getEnergyPoints()
				<< std::setw(10) << "damage: " << name.getAttackDamage()
				<< RESET << std::endl;	
}

int main() {
	{
		DiamondTrap rocket1;
		rocket1.whoAmI();
		print_status(rocket1);
	}
	std::cout << std::endl;

	DiamondTrap	rocket("Rocket");
	print_status(rocket);

	std::cout << "\n----Who Am I----" << std::endl;
	rocket.whoAmI();

	std::cout << "\n----Making attack----" << std::endl;
	print_status(rocket);
	rocket.attack("Adam");	// ScavTrap

	std::cout << "\n----Being attacked----" << std::endl;
	print_status(rocket);
	rocket.takeDamage(50); // ClapTrap
	print_status(rocket);

	std::cout << "\n----Being repaired----" << std::endl;
	print_status(rocket);
	rocket.beRepaired(10);	// ClapTrap
	print_status(rocket);

	std::cout << "\n----No energy/hit points----" << std::endl;
	rocket.setHitPoints(0);
	print_status(rocket);
	rocket.attack("Adam");	// ScavTrap
	rocket.beRepaired(10);	// ClapTrap
	rocket.setHitPoints(20);
	rocket.setEnergyPoints(1);
	print_status(rocket);
	rocket.attack("Adam");	// ScavTrap
	rocket.attack("Adam");	// ScavTrap
	print_status(rocket);

	return 0;
}