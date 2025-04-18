/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:12:53 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 12:43:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**) {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	// Set values
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "Test if we set values right" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "Ding ding ding~. Everything is fine." << std::endl;
	std::cout << std::endl;

	{
		std::cout << "Test copy constructor and copy assignment operator" << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != tmp[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != test[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		std::cout << "Ding ding ding~. Everything is fine." << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test []" << std::endl;
	std::cout << "Negative index" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Index too big" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}