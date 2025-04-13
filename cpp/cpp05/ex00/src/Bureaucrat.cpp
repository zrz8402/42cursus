/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:30 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/13 16:52:26 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("Unnamed") {
	setGrade(DEFAULT);
}

Bureaucrat::Bureaucrat( std::string const name, int const grade ) : name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : name(other.name), grade(other.grade) {}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat &other ) {
	if (this != &other) {
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}

void	Bureaucrat::setGrade( int const grade ) {
	if (grade < HIGHEST)
		throw GradeTooHighException();
	if (grade > LOWEST)
		throw GradeTooLowException();
	this->grade = grade;
}

std::string	Bureaucrat::getName( void ) const {
	return name;
}

int	Bureaucrat::getGrade( void ) const {
	return grade;
}

void	Bureaucrat::increment( void ) {
	setGrade(grade - 1);
}

void	Bureaucrat::decrement( void ) {
	setGrade(grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}
