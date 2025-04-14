/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 17:15:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) 
	: AForm(DEFAULT_RRNAME, DEFAULT_RRSIGN, DEFAULT_RREXEC),
		target("")
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm( std::string const target )
	: AForm(DEFAULT_RRNAME, DEFAULT_RRSIGN, DEFAULT_RREXEC),
	target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other )
	: AForm(DEFAULT_RRNAME, DEFAULT_RRSIGN, DEFAULT_RREXEC),
	target(other.target)
{
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		if (beExecuted(executor)) {
			std::cout << executor.getName() << " executed " << getName() << std::endl;
			robotomize();
		}
	} catch(std::exception &e) {
		std::cerr << RED << executor.getName() << " couldn't execute " << getName()
					<< " because " << e.what() << ".\n" << RESET;
	}
}

void	RobotomyRequestForm::robotomize() const{
	std::cout << GREEN << "BZZZZZZZZZZZZ......" << RESET << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << GREEN << target << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << RED << "The robotomy failed on " << target << RESET << std::endl;
}
