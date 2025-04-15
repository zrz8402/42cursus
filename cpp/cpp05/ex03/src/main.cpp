/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:27 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/15 17:03:18 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	Intern	ron;
	AForm*	rrf;

	rrf = ron.makeForm("PresidentialPardonForm", "tom");
	std::cout << *rrf;
	Bureaucrat b("Tom", 1);
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;
	std::cout << std::endl;

	rrf = ron.makeForm("RobotomyRequestForm", "jerry");
	std::cout << *rrf;
	delete rrf;
	std::cout << std::endl;

	rrf = ron.makeForm("ShrubberyCreationForm", "mike");
	std::cout << *rrf;
	delete rrf;
	std::cout << std::endl;

	rrf = ron.makeForm("form", "");
	delete rrf;
}