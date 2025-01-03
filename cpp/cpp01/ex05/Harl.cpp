/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:17:37 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 17:12:34 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n" 
				<< "I really do!" 
				<< std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]\n"
				<< "I cannot believe adding extra bacon costs more money.\n" 
				<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" 
				<< std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I've been coming for years whereas you started working here since last month."
				<< std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]\n"
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void	Harl::complain( std::string level ) {
	std::string levels[] = { "debug", "info", "warning", "error" };
	void (Harl::*funcs[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}