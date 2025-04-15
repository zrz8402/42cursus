/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:27 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/15 15:53:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// sign 25; exec 5
void	testPP() {
	std::cout << "Testing PresidentialPardonForm----------" << std::endl;
	std::cout << "\nCase 1: success" << std::endl;
	{
		Bureaucrat b("Tom", 1);
		PresidentialPardonForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 2: execGrade not enough" << std::endl;
	{
		Bureaucrat b("Tom", 6);
		PresidentialPardonForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 3: not signed" << std::endl;
	{
		Bureaucrat b("Tom", 1);
		PresidentialPardonForm ron("Ron");
		// b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 4: not signed; signGrade not enough" << std::endl;
	{
		Bureaucrat b("Tom", 30);
		PresidentialPardonForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
}

// 72, 45
void	testRR() {
	std::cout << "Testing RobotomyRequestForm----------" << std::endl;
	std::cout << "\nCase 1: success" << std::endl;
	{
		Bureaucrat b("Tom", 1);
		RobotomyRequestForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 2: execGrade not enough" << std::endl;
	{
		Bureaucrat b("Tom", 46);
		RobotomyRequestForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 3: not signed" << std::endl;
	{
		Bureaucrat b("Tom", 1);
		RobotomyRequestForm ron("Ron");
		// b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 4: not signed; signGrade not enough" << std::endl;
	{
		Bureaucrat b("Tom", 73);
		RobotomyRequestForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
}

// 145, 137
void	testSC() {
	std::cout << "Testing ShrubberyCreationForm----------" << std::endl;
	std::cout << "\nCase 1: success" << std::endl;
	{
		Bureaucrat b("Tom", 1);
		ShrubberyCreationForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 2: execGrade not enough" << std::endl;
	{
		Bureaucrat b("Tom", 138);
		ShrubberyCreationForm ron("Ron");
		b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 3: not signed" << std::endl;
	{
		Bureaucrat b("Tom", 1);
		ShrubberyCreationForm ron("Ron");
		// b.signForm(ron);
		b.executeForm(ron);
	}
	std::cout << "\nCase 4: not signed; signGrade not enough" << std::endl;
	{
		Bureaucrat b("Tom", 150);
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