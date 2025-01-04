/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:05:10 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/04 15:56:55 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

/*
$> ./a.out
->Fixed a;
Default constructor called

->Fixed b( a );
Copy constructor called
Copy assignment operator called  <-- This line may be missing depending on your implementation
getRawBits member function called

->Fixed c;
Default constructor called
->c = b;
Copy assignment operator called
getRawBits member function called

->std::cout << a.getRawBits() << std::endl;
->std::cout << b.getRawBits() << std::endl;
->std::cout << c.getRawBits() << std::endl;
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0

Destructor called
Destructor called
Destructor called
*/