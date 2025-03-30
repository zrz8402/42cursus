/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:29 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 16:38:17 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iomanip>

void	print_status(ClapTrap &name) {
	std::cout << GREEN << "Current status:" << std::endl;
	std::cout << name.getName() 
				<< std::setw(7) << "hp: " << name.getHitPoints()
				<< std::setw(7) << "ep: " << name.getEnergyPoints()
				<< std::setw(10) << "damage: " << name.getAttackDamage()
				<< RESET << std::endl;	
}

int main() {
	ClapTrap	rocket("Rocket");

	print_status(rocket);

	std::cout << "\n----Making attack----" << std::endl;
	print_status(rocket);
	rocket.attack("Adam");
	std::cout << YELLOW << "Set attackDamage to 2" << RESET << std::endl;
	rocket.setAttackDamage(2);
	print_status(rocket);
	rocket.attack("Adam");

	std::cout << "\n----Being attacked----" << std::endl;
	print_status(rocket);
	rocket.takeDamage(5);
	print_status(rocket);
	std::cout << YELLOW << "Set hitPoints to 3" << RESET << std::endl;
	rocket.setHitPoints(3);
	rocket.takeDamage(5);
	print_status(rocket);

	std::cout << "\n----Being repaired----" << std::endl;
	print_status(rocket);
	std::cout << YELLOW << "Set hitPoints to 3" << RESET << std::endl;
	rocket.setHitPoints(3);
	print_status(rocket);
	rocket.beRepaired(10);
	print_status(rocket);

	std::cout << "\n----No energy/hit points----" << std::endl;
	std::cout << YELLOW << "Set hitPoints to 0" << RESET << std::endl;
	rocket.setHitPoints(0);
	print_status(rocket);

	rocket.takeDamage(5);
	rocket.attack("Adam");
	rocket.beRepaired(10);

	std::cout << YELLOW << "Set energyPoints to 1" << RESET << std::endl;
	rocket.setHitPoints(1);
	print_status(rocket);
	rocket.attack("Adam");
	rocket.attack("Adam");
	rocket.attack("Adam");
	rocket.attack("Adam");
	rocket.attack("Adam");
	rocket.attack("Adam");
	rocket.attack("Adam");
	print_status(rocket);
	rocket.attack("Adam");
	
	return 0;
}