/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:53:29 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/10 15:54:11 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iomanip>

void	print_status(ScavTrap &name) {
	std::cout << "Current status:" << std::endl;
	std::cout << name.getName() 
				<< std::setw(6) << " hp: " << name.getHp()
				<< std::setw(6) << " ep: " << name.getEp()
				<< std::setw(10) << " damage: " << name.getDamage()
				<< std::endl;	
}

int main() {
	ScavTrap	rocket("Rocket");

	print_status(rocket);

	// std::cout << "\n----Making attack----" << std::endl;
	// rocket.attack("Adam");
	// print_status(rocket);

	// std::cout << "\n----Being attacked----" << std::endl;
	// rocket.takeDamage(100);
	// print_status(rocket);

	// std::cout << "\n----Being repaired----" << std::endl;
	// rocket.beRepaired(10);
	// print_status(rocket);

	// std::cout << "\n----Guard mode----" << std::endl;
	// rocket.guardGate();

	// std::cout << "\n----No energy/hit points----" << std::endl;
	// rocket.setHp(0);
	// print_status(rocket);
	// rocket.attack("Adam");
	// rocket.beRepaired(10);
	// rocket.setEp(1);
	// rocket.attack("Adam");
	// rocket.attack("Adam");
	// print_status(rocket);
	
	return 0;
}