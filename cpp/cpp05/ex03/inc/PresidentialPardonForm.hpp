/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:28:30 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:05:02 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define DEFAULT_PPNAME	"PresidentialPardonForm"
#define DEFAULT_PPSIGN	25
#define DEFAULT_PPEXEC	5

class Bureaucrat;

class PresidentialPardonForm : public AForm {

private:
	std::string const	target;

public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string const target );
	PresidentialPardonForm( const PresidentialPardonForm &other );
	PresidentialPardonForm& operator=( const PresidentialPardonForm &other );
	virtual ~PresidentialPardonForm(void);

	void	execute(Bureaucrat const & executor) const;
};

#endif