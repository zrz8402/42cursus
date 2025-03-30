/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:29 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 16:41:40 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

void	print_status(ScavTrap &name) {
	std::cout << GREEN << "Current status:" << std::endl;
	std::cout << name.getName() 
				<< std::setw(7) << "hp: " << name.getHitPoints()
				<< std::setw(7) << "ep: " << name.getEnergyPoints()
				<< std::setw(10) << "damage: " << name.getAttackDamage()
				<< RESET << std::endl;	
}

int main() {
	ScavTrap	rocket("Rocket");

	print_status(rocket);

	std::cout << "\n----Making attack----" << std::endl;
	print_status(rocket);
	rocket.attack("Adam");
	std::cout << YELLOW << "Set attackDamage to 30" << RESET << std::endl;
	rocket.setAttackDamage(30);
	print_status(rocket);
	rocket.attack("Adam");

	std::cout << "\n----Being attacked----" << std::endl;
	print_status(rocket);
	rocket.takeDamage(25);
	print_status(rocket);
	std::cout << YELLOW << "Set hitPoints to 20" << RESET << std::endl;
	rocket.setHitPoints(20);
	rocket.takeDamage(25);
	print_status(rocket);

	std::cout << "\n----Being repaired----" << std::endl;
	print_status(rocket);
	std::cout << YELLOW << "Set hitPoints to 30" << RESET << std::endl;
	rocket.setHitPoints(30);
	print_status(rocket);
	rocket.beRepaired(30);
	print_status(rocket);

	std::cout << "\n----Guard mode----" << std::endl;
	rocket.guardGate();

	std::cout << "\n----No energy/hit points----" << std::endl;
	std::cout << YELLOW << "Set hitPoints to 0" << RESET << std::endl;
	rocket.setHitPoints(0);
	print_status(rocket);

	rocket.takeDamage(5);
	rocket.attack("Adam");
	rocket.beRepaired(10);

	std::cout << YELLOW << "Set energyPoints to 30" << RESET << std::endl;
	std::cout << YELLOW << "Set energyPoints to 2" << RESET << std::endl;
	rocket.setHitPoints(30);
	rocket.setEnergyPoints(2);
	print_status(rocket);
	rocket.attack("Adam");
	rocket.attack("Adam");
	print_status(rocket);
	rocket.attack("Adam");
	
	return 0;
}
