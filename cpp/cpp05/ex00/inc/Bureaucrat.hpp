/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:32 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/13 17:18:09 by ruzhang          ###   ########.fr       */
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

#define	LOWEST	150
#define HIGHEST	1
#define DEFAULT	20

class Bureaucrat {

private:
	const std::string	name;
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

	class GradeTooHighException : public std::exception {
	
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	
	public:
		const char* what() const throw();
	};
	
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);

/*
`const char* what() const throw();`
const char*: Return type;
what():
	It’s called what, by convention and standard (defined in std::exception).
	It returns a description of the exception.
throw():
	C++98-style exception specification
	It means: "This function is guaranteed not to throw any exceptions."
	This allows the compiler to optimize and enforce exception safety
	Modern C++ replaces this with noexcept
	`const char* what() const noexcept override;`
*/

#endif