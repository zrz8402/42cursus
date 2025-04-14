/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:27 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 11:22:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testTooHigh() {
	std::cout << "Testing too high" << std::endl;
	{
		try {
			Bureaucrat tom("Tom", 0);
			std::cout << tom;
		} catch( std::exception &e ) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			Bureaucrat tom("Tom", 1);
			std::cout << tom;
			std::cout << BLUE << "Increment" << RESET << std::endl;
			tom.increment();
			std::cout << tom;
		} catch( std::exception &e ) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
}

void	testTooLow() {
	std::cout << "Testing too low" << std::endl;
	{
		try {
			Bureaucrat tom("Tom", 151);
			std::cout << tom;
		} catch( std::exception &e ) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			Bureaucrat tom("Tom", 150);
			std::cout << tom;
			std::cout << BLUE << "Decrement" << RESET << std::endl;
			tom.decrement();
			std::cout << tom;
		} catch( std::exception &e ) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
}

void	testNormal() {
	std::cout << "Testing normal" << std::endl;
	{
		try {
			Bureaucrat tom;
			std::cout << tom;
			tom.decrement();
			std::cout << tom;
		} catch( std::exception &e ) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
}

int	main() {
	testTooHigh();
	std::cout << std::endl;
	testTooLow();
	std::cout << std::endl;
	testNormal();
}

/*
Testing copy constructor and copy assignment operator

Bureaucrat tom("Tom", 1);
std::cout << tom;

Bureaucrat jerry;
jerry = tom;
std::cout << jerry;

Bureaucrat jerry2("jerry", 100);
std::cout << jerry2;
jerry2 = tom;
std::cout << jerry2;
*/