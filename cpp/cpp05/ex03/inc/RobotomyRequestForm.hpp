/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:28:51 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/15 15:18:16 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

#define DEFAULT_RRNAME	"RobotomyRequestForm"
#define DEFAULT_RRSIGN	72
#define DEFAULT_RREXEC	45

class Bureaucrat;

class RobotomyRequestForm : public AForm {

private:
	std::string const	target;

	void	robotomize() const;

public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string const target );
	RobotomyRequestForm( const RobotomyRequestForm &other );
	RobotomyRequestForm& operator=( const RobotomyRequestForm &other );
	virtual ~RobotomyRequestForm(void);

	void	execute(Bureaucrat const & executor) const;
};

#endif