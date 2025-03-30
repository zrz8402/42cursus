/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:04:07 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 12:33:41 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/*
More efficient
directly initializes value to 0 in the initializer list
*/
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*
initializes value with its default constructor
(to a potentially undefined value)
then assigns it 0 within the constructor body.
```
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}
```
*/


/*
`*this = other;`
should be avoided because it uses the assignment operator,
which adds unnecessary overhead.

`: value(other.value)`
most efficient and recommended way to implement the copy constructor
```
Fixed::Fixed( const Fixed &other ) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}
```
```
Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}
```
*/
// calls `copy assignment operator`
Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
`getRawBits()`
keep a clean, maintainable codebase with good encapsulation.
if will modify or extend the behavior of getting value 
(e.g., adding logging, error checking, or transformation).

`other.value)`
absolute simplest solution and don’t care about encapsulation.
optimizw for speed and the getter method does not add any meaningful logic.
value is meant to be accessed directly and there's no need for extra logic or abstraction.
```
Fixed& Fixed::operator=( const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.value;
	return *this;
}
```
*/
Fixed& Fixed::operator=( const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits( int const raw ) {
	value = raw;
}
