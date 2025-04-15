/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:07:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:57:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include <fstream>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define DEFAULT_SCNAME	"ShrubberyCreationForm"
#define DEFAULT_SCSIGN	145
#define DEFAULT_SCEXEC	137

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

private:
	std::string const	target;

	void	writeFile() const;

public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string const target);
	ShrubberyCreationForm( const ShrubberyCreationForm &other );
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm &other );
	virtual ~ShrubberyCreationForm(void);

	void	execute(Bureaucrat const & executor) const;
};

#endif