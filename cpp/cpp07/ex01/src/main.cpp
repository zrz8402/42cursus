/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:13:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 11:33:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cmath>

template <typename T>
void	printString(const T &value) {
	std::cout << value << std::endl;
}

template <typename T>
void	printLength(const T &value) {
	std::cout << value << " length: " << value.length() << std::endl;
}

template <typename T>
void	printNum(const T &value) {
	std::cout << value << std::endl;
}

template <typename T>
void	power(T &value) {
	value = std::pow(value, 2);
}

int	main() {

	{
		std::string	planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
		size_t		len = sizeof(planets) / sizeof(planets[0]);

		iter(planets, len, printString<std::string>);
		std::cout << std::endl;
		iter(planets, len, printLength<std::string>);
		std::cout << std::endl;
	}

	{
		int		arr[] = {1, 2, 3, 4, 5};
		size_t	len = sizeof(arr) / sizeof(arr[0]);

		iter(arr, len, printNum<int>);
		std::cout << std::endl;
		iter(arr, len, power<int>);
		iter(arr, len, printNum<int>);
		std::cout << std::endl;
	}
}
