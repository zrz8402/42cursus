/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:35 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:56:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) 
	: AForm(DEFAULT_PPNAME, DEFAULT_PPSIGN, DEFAULT_PPEXEC),
		target("")
{}

PresidentialPardonForm::PresidentialPardonForm( std::string const target )
	: AForm(DEFAULT_PPNAME, DEFAULT_PPSIGN, DEFAULT_PPEXEC),
	target(target)
{}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other )
	: AForm(DEFAULT_PPNAME, DEFAULT_PPSIGN, DEFAULT_PPEXEC),
	target(other.target)
{
	*this = other;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		if (beExecuted(executor)) {
			std::cout << executor.getName() << " executed " << getName() << std::endl;
			std::cout << GREEN << target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
		}
	} catch(std::exception &e) {
		std::cerr << RED << executor.getName() << " couldn't execute " << getName()
					<< " because " << e.what() << ".\n" << RESET;
	}
}
