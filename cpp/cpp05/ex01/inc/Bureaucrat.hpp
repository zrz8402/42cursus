/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:32 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 15:39:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include <iostream>
#include "Form.hpp"

#define	LOWEST	150
#define HIGHEST	1
#define DEFAULT	20

class Form;

class Bureaucrat {

private:
	std::string const	name;
	int					grade;

	void	setGrade( int const grade );

public:
	Bureaucrat( void );
	Bureaucrat( std::string const name, int const grade );
	Bureaucrat( const Bureaucrat &other );
	Bureaucrat&	operator=( const Bureaucrat &other );
	~Bureaucrat( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;

	void		increment( void );
	void		decrement( void );

	void		signForm(Form &form) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);

#endif