/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:41:27 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/14 12:56:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testSignForm() {
	std::cout << "Test signForm\n";
	{
		Form	jerry("Jerry", 80, 70);
		std::cout << jerry;
		std::cout << std::endl;

		Bureaucrat tom("Tom", 20);
		std::cout << tom;
		tom.signForm(jerry);
		std::cout << std::endl;

		Bureaucrat mike("Mike", 90);
		std::cout << mike;
		mike.signForm(jerry);
	}
}

void	testForm()
{
	std::cout << "Test Form\n";
	{
		try {
			Form	jerry("Jerry", 151, 70);
		} catch(std::exception &e) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}

	{
		try {
			Form	jerry("Jerry", 100, 0);
		} catch(std::exception &e) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
}

int	main() {
	testForm();
	std::cout << std::endl;
	testSignForm();
}