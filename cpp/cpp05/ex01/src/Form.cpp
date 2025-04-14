/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:39:41 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 13:00:16 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void )
	: name("Unnamed"),
		signGrade(DEFAULT_SIGN),
		execGrade(DEFAULT_EXEC)
{
	checkGrade();
	isSigned = false;
}

Form::Form( std::string const name, int signGrade, int execGrade )
	: name(name),
	signGrade(signGrade),
	execGrade(execGrade)
{
	checkGrade();
	isSigned = false;
}

Form::Form( const Form &other ) 
	: name(other.name),
		isSigned(other.isSigned),
		signGrade(other.signGrade),
		execGrade(other.execGrade)
{}

Form&	Form::operator=( const Form &other ) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form( void ) {}

void	Form::checkGrade( void ) {
	if (signGrade < HIGHEST || execGrade < HIGHEST)
		throw GradeTooHighException();
	if (signGrade > LOWEST || execGrade > LOWEST)
		throw GradeTooLowException();
}

std::string	Form::getName( void ) const {
	return name;
}

bool	Form::getSigned( void ) const {
	return isSigned;
}

int	Form::getSignGrade( void ) const {
	return signGrade;
}

int	Form::getExecGrade( void ) const {
	return execGrade;
}

void	Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form &obj) {
	os << "Form Details: \n"
		<< "Name: " << obj.getName() << "\n"
		<< "IsSigned: " << (obj.getSigned() ? "Yes" : "No") << "\n"
		<< "Sign Grade Required: " << obj.getSignGrade() << "\n"
		<< "Execuation Grade Required: " << obj.getExecGrade() << "\n";
	return os;
}
