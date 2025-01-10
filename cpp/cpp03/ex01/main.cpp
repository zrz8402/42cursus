/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:29 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 17:53:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

void	print_status(ScavTrap &name) {
	std::cout << "Current status:" << std::endl;
	std::cout << name.getName() 
				<< std::setw(7) << "hp: " << name.getHitPoints()
				<< std::setw(7) << "ep: " << name.getEnergyPoints()
				<< std::setw(10) << "damage: " << name.getAttackDamage()
				<< std::endl;	
}

int main() {
	ScavTrap	rocket("Rocket");

	print_status(rocket);

	std::cout << "\n----Making attack----" << std::endl;
	rocket.attack("Adam");
	print_status(rocket);

	std::cout << "\n----Being attacked----" << std::endl;
	rocket.takeDamage(50);
	print_status(rocket);

	std::cout << "\n----Being repaired----" << std::endl;
	rocket.beRepaired(10);
	print_status(rocket);

	std::cout << "\n----No energy/hit points----" << std::endl;
	rocket.setHitPoints(0);
	print_status(rocket);
	rocket.attack("Adam");
	rocket.beRepaired(10);
	rocket.setHitPoints(1);
	print_status(rocket);
	rocket.attack("Adam");
	rocket.setEnergyPoints(1);
	print_status(rocket);
	rocket.attack("Adam");
	rocket.attack("Adam");
	print_status(rocket);
	
	return 0;
}