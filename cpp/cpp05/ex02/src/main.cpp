/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:27 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:58:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testPP() {
	std::cout << "Testing PresidentialPardonForm" << std::endl;
	
	{
		Bureaucrat b("Tom", 1);
		PresidentialPardonForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
		std::cout << std::endl;
	}
}

void	testRR() {
	std::cout << "Testing RobotomyRequestForm" << std::endl;

	{
		Bureaucrat b("Tom", 1);
		RobotomyRequestForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
		std::cout << std::endl;
	}
}

void	testSC() {
	std::cout << "Testing ShrubberyCreationForm" << std::endl;

	{
		Bureaucrat b("Tom", 1);
		ShrubberyCreationForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
}

int	main() {
	testPP();
	std::cout << std::endl;
	testRR();
	std::cout << std::endl;
	testSC();
}