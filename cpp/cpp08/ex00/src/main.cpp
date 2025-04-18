/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:23 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 14:57:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(int, char**) {
	std::vector<int> numbers;

	numbers.push_back(1);
	numbers.push_back(11);
	numbers.push_back(14);
	numbers.push_back(17);
	numbers.push_back(19);

	try {
		std::vector<int>::const_iterator	it = easyfind(numbers, 3);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator	it = easyfind(numbers, 11);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
}
