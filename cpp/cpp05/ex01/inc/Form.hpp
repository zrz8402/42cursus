/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:25:20 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 15:38:51 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"

#define	LOWEST			150
#define HIGHEST			1
#define DEFAULT_SIGN	80
#define DEFAULT_EXEC	30

class Bureaucrat;

class Form {

private:
	std::string const	name;
	bool				isSigned;
	int	const			signGrade;
	int const			execGrade;

	void		checkGrade( void );

public:
	Form( void );
	Form( std::string const name, int signGrade, int execGrade );
	Form( const Form &other );
	Form& operator=( const Form &other );
	~Form(void);

	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getSignGrade( void ) const;
	int			getExecGrade( void ) const;

	void	beSigned(const Bureaucrat &b);

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

};

std::ostream& operator<<(std::ostream& os, const Form &obj);

#endif