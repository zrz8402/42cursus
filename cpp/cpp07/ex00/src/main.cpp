/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:04:18 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/17 16:36:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

void	testSwap() {
	std::cout << "Testing swap " << std::endl;
	int	a = 5;
	int	b = 15;

	std::cout << "Original: ";
	std::cout << "a: " << a << ", b: " << b << std::endl;

	swap(a, b);
	std::cout << "After swap: ";
	std::cout << "a: " << a << ", b: " << b << std::endl;
}

int main() {

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;

	testSwap();

	return 0;
}
