/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:40:39 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 14:12:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;

	std::cout << "original a: " << a << std::endl; // 0

	std::cout << "\npre-/post-increment" << std::endl;
	std::cout << "++a: "<< ++a << std::endl; // 0.00390625
	std::cout << "a after ++a: "<< a << std::endl; // 0.00390625
	std::cout << "a++: "<< a++ << std::endl; // 0.00390625
	std::cout << "a after a++: "<< a << std::endl; // 0.0078125

	std::cout << "\npre-/post-decrement" << std::endl;
	std::cout << "--a: "<< --a << std::endl;
	std::cout << "a after --a: "<< a << std::endl;
	std::cout << "a--: "<< a-- << std::endl;
	std::cout << "a after a--: "<< a << std::endl;

	/*
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed(5.05f) -> 5.05 * 256 = 1292.8 ->roundf -> 1293
		Fixed( 2 ) -> 2 * 256 = 512
		1293 / 256 * 2 / 256 = 10.1015625 -> close to 10.1016
	*/
	std::cout << std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "b: " << b << std::endl; // 10.1016

	std::cout << "\nmin & max" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// const Fixed x1(3);
	// const Fixed y1(4);
	// std::cout << "const: " << Fixed::min(x1, y1) << std::endl;
	// Fixed x2(3);
	// Fixed y2(4);
	// std::cout << "not const: " << Fixed::min(x2, y2) << std::endl;

	// std::cout << "\ncomparison operators" << std::endl;
	// std::cout << (a > b) << std::endl;
	// std::cout << (a <= b) << std::endl;
	// std::cout << (a == b) << std::endl;
	// std::cout << (a != b) << std::endl;

	// std::cout << "\narithmetic operators" << std::endl;
	// Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
	// std::cout << c << std::endl; // 7.05078

	// divided by zero
	// Fixed const d( Fixed( 5.05f ) / Fixed( 0.001f ) );

	return 0;
}
