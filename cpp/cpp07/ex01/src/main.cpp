/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:13:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 11:40:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cmath>

/*
A generic function blueprint using template <typename T>
Creating a specific version like myFunc<int>
	printValue<std::string>
	printValue<int>
*/
template <typename T>
void	printValue(const T &value) {
	std::cout << value << std::endl;
}

template <typename T>
void	printLength(const T &value) {
	std::cout << value << " length: " << value.length() << std::endl;
}

template <typename T>
void	power(T &value) {
	value = std::pow(value, 2);
}

int	main() {

	{
		std::string	planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
		size_t		len = sizeof(planets) / sizeof(planets[0]);

		iter(planets, len, printValue<std::string>);
		std::cout << std::endl;
		iter(planets, len, printLength<std::string>);
		std::cout << std::endl;
	}

	{
		int		arr[] = {1, 2, 3, 4, 5};
		size_t	len = sizeof(arr) / sizeof(arr[0]);

		iter(arr, len, printValue<int>);
		std::cout << std::endl;
		iter(arr, len, power<int>);
		iter(arr, len, printValue<int>);
		std::cout << std::endl;
	}
}
