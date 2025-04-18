/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:13:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 11:17:02 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void	printString(std::string &str) {
	std::cout << str << std::endl;
}

template <typename T>
void	printLength(T value) {
	std::cout << value << " length: " << value.length() << std::endl;
}

void	printLength2(std::string &str) {
	std::cout << str << " length: " << str.length() << std::endl;
}

int	main() {
	std::string	planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune",};
	size_t	len = sizeof(planets) / sizeof(planets[0]);

	iter(planets, len, printString);
	std::cout << std::endl;
	iter(planets, len, printLength<std::string>);
	std::cout << std::endl;
	iter(planets, len, printLength2);
}
