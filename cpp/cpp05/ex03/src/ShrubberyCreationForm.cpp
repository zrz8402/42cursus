/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:08:41 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 16:55:35 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char* tree[] = {
    "              *              ",
    "             /o\\             ",
    "            /o*o\\            ",
    "           /oXoXo\\           ",
    "          /o*oXo*o\\          ",
    "         /oXoXoXoXo\\         ",
    "        /o*o*oXo*o*o\\        ",
    "       /oXoXo*oXoXoXo\\       ",
    "      /o*oXoXo*oXo*oXo\\      ",
    "     /oXoXoXoXo*oXoXoXo\\     ",
    "            |||||             ",
    "            |||||             ",
    "            |||||             ",
    "            |||||             ",
    "            |||||             ",
    "            |||||             "
};

ShrubberyCreationForm::ShrubberyCreationForm( void ) 
	: AForm(DEFAULT_SCNAME, DEFAULT_SCSIGN, DEFAULT_SCEXEC),
		target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target )
	: AForm(DEFAULT_SCNAME, DEFAULT_SCSIGN, DEFAULT_SCEXEC),
	target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other )
	: AForm(DEFAULT_SCNAME, DEFAULT_SCSIGN, DEFAULT_SCEXEC),
	target(other.target)
{
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void	ShrubberyCreationForm::writeFile() const{
	std::string		filename = target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	if (!outfile.is_open()) {
		std::cerr << RED << "Error creating output file stream: " << filename << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 16; i++) {
		outfile << tree[i] << std::endl;
	}
	std::cout << GREEN << filename << " is created." << RESET << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		if (beExecuted(executor)) {
			std::cout << executor.getName() << " executed " << getName() << std::endl;
			writeFile();
		}
	} catch(std::exception &e) {
		std::cerr << RED << executor.getName() << " couldn't execute " << getName()
					<< " because " << e.what() << ".\n" << RESET;
	}
}
