/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:30 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:48:24 by ruzhang          ###   ########.fr       */
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

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e){
		std::cerr << RED << name << " couldn't sign " << form.getName()
					<< " because " << e.what() << ".\n" << RESET;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
	} catch(std::exception &e) {
		std::cerr << RED << name << " couldn't execute " << form.getName()
					<< " because " << e.what() << ".\n" << RESET;
	}
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
