/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:54:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/15 16:38:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

public:
	Intern( void );
	Intern( const Intern &other );
	Intern& operator=( const Intern &other );
	virtual ~Intern(void);

	AForm*			makeForm( std::string formName, std::string target );
	static AForm*	makePresidentialPardonForm( std::string const target );
	static AForm*	makeRobotomyRequestForm( std::string const target );
	static AForm*	makeShrubberyCreationForm( std::string const target );

};

#endif