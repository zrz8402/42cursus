/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:27 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/29 16:49:06 by ruzhang          ###   ########.fr       */
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
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			i = -1;
	
	while (++i < 4) {
		if (level == levels[i])
			break;
	}
	
	switch (i)
	{
		case 0:
			debug();
			std::cout << std::endl;
		case 1:
			info();
			std::cout << std::endl;
		case 2:
			warning();
			std::cout << std::endl;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}