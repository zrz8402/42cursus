/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:23 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 16:56:42 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <iostream>
#include <iterator>

int	main(int, char**) {
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printElements();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		std::cout << "Test adding numbers when the vector is full" << std::endl;
		try {
			sp.addNumber(3);
		} catch(std::length_error &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		Span				sp = Span(10);
		std::vector<int>	numbers;	
		for (int i = 0; i < 5; i++) {
			numbers.push_back(i * 2);
		}

		std::cout << "Test adding multiple numbers" << std::endl;
		try {
			std::cout << "first add" << std::endl;
			sp.addMultipleNum(numbers.begin(), numbers.end());
			sp.printElements();
		} catch(std::length_error &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << "Second add" << std::endl;
			sp.addMultipleNum(numbers.begin(), numbers.end());
			sp.printElements();
		} catch(std::length_error &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << "Third add" << std::endl;
			sp.addMultipleNum(numbers.begin(), numbers.end());
			sp.printElements();
		} catch(std::length_error &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
