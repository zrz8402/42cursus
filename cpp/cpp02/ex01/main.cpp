/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:05:10 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 13:08:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	// std::cout << std::endl;
	// std::cout << "a is " << a.toFloat() << std::endl;
	// std::cout << "a is " << b.toFloat() << std::endl;
	// std::cout << "a is " << c.toFloat() << std::endl;
	// std::cout << "a is " << d.toFloat() << std::endl;

	std::cout << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl;
	return 0;
}

/*
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called

Float constructor called
Copy assignment operator called
Destructor called

a is 1234.43
b is 10
c is 42.4219
d is 10

a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer

Destructor called
Destructor called
Destructor called
Destructor called
$>
*/