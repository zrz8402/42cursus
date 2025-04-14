/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:25:20 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:03:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"

#define	LOWEST			150
#define HIGHEST			1
#define DEFAULT_SIGN_GRADE	80
#define DEFAULT_EXEC_GRADE	30

class Bureaucrat;

class AForm {

private:
	std::string const	name;
	bool				isSigned;
	int	const			signGrade;
	int const			execGrade;

	void		checkGrade( void );

public:
	AForm( void );
	AForm( std::string const name, int signGrade, int execGrade );
	AForm( const AForm &other );
	AForm& operator=( const AForm &other );
	virtual ~AForm(void);

	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getSignGrade( void ) const;
	int			getExecGrade( void ) const;

	void			beSigned( const Bureaucrat &b );
	bool			beExecuted( Bureaucrat const & executor ) const;
	virtual void	execute( Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const AForm &obj);

#endif