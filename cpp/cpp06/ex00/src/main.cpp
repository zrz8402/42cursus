/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:49:50 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/16 15:40:19 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char *av[]) {
	if (ac == 1) {
		std::cout << "NO ARG" << std::endl;
		return 0;
	}

	for (int i = 1; i < ac; i++) {
		std::cout << "literal: " << av[i] << std::endl;
		ScalarConverter::convert(av[i]);
		std::cout << std::endl;
	}
	
	return 0;
}

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/