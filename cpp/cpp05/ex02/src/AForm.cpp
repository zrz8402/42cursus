/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:39:41 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:14:37 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void )
	: name("Unnamed"),
		signGrade(DEFAULT_SIGN_GRADE),
		execGrade(DEFAULT_EXEC_GRADE)
{
	checkGrade();
	isSigned = false;
}

AForm::AForm( std::string const name, int signGrade, int execGrade )
	: name(name),
	signGrade(signGrade),
	execGrade(execGrade)
{
	checkGrade();
	isSigned = false;
}

AForm::AForm( const AForm &other ) 
	: name(other.name),
		isSigned(other.isSigned),
		signGrade(other.signGrade),
		execGrade(other.execGrade)
{}

AForm&	AForm::operator=( const AForm &other ) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm( void ) {}

void	AForm::checkGrade( void ) {
	if (signGrade < HIGHEST || execGrade < HIGHEST)
		throw GradeTooHighException();
	if (signGrade > LOWEST || execGrade > LOWEST)
		throw GradeTooLowException();
}

std::string	AForm::getName( void ) const {
	return name;
}

bool	AForm::getSigned( void ) const {
	return isSigned;
}

int	AForm::getSignGrade( void ) const {
	return signGrade;
}

int	AForm::getExecGrade( void ) const {
	return execGrade;
}

void	AForm::beSigned( const Bureaucrat &b ) {
	if (b.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

bool	AForm::beExecuted( Bureaucrat const & executor ) const{
	if (!getSigned())
	{
		throw FormNotSignedException();
		return false;
	}
	if (executor.getGrade() > execGrade)
	{
		throw GradeTooLowException();
		return false;
	}
	return true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "form isn't signed";
}

std::ostream& operator<<(std::ostream& os, const AForm &obj) {
	os << "AForm Details: \n"
		<< "Name: " << obj.getName() << "\n"
		<< "IsSigned: " << (obj.getSigned() ? "Yes" : "No") << "\n"
		<< "Sign Grade Required: " << obj.getSignGrade() << "\n"
		<< "Execuation Grade Required: " << obj.getExecGrade() << "\n";
	return os;
}
