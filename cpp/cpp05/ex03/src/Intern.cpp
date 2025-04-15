/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:54:45 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/15 16:53:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern &other ) {
	*this = other;
}

Intern& Intern::operator=( const Intern &other ) {
	if (this != &other) {
		*this = other;
	}
	return (*this);
}

Intern::~Intern(void) {}

AForm*	Intern::makeForm( std::string formName, std::string target ) {
	const std::string forms[] = { "PresidentialPardonForm",
							"RobotomyRequestForm",
							"ShrubberyCreationForm" };
	AForm* (*funcs[])(std::string const target) = { &makePresidentialPardonForm,
							&makeRobotomyRequestForm,
							&makeShrubberyCreationForm};

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			std::cout << GREEN << "Intern creates " << forms[i] << RESET << std::endl;
			return funcs[i](target);
		}
	}
	std::cout << RED << "Error: Intern is unable to creates " << formName << RESET << std::endl;
	return NULL;
}

AForm*	Intern::makePresidentialPardonForm( std::string const target ) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeRobotomyRequestForm( std::string const target ) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makeShrubberyCreationForm( std::string const target ) {
	return new ShrubberyCreationForm(target);
}
