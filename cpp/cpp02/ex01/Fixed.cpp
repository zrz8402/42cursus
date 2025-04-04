/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:04:07 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 13:01:49 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	return value;
}

void	Fixed::setRawBits( int const raw ) {
	value = raw;
}

/*
convert number V into its fixed-point representation N;
n: fractional bits
N = round(V * 2 ^ n)
`value << FRACTIONAL_BITS`
	often more efficient
	only apply to integers
`value * (1 << FRACTIONAL_BITS)`
*/
Fixed::Fixed( const int value ) : value(value << FRACTIONAL_BITS) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value ) : value(roundf(value * (1 << FRACTIONAL_BITS))) {
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat( void ) const{
	return (float)value / (1 << FRACTIONAL_BITS);
}

int		Fixed::toInt( void ) const{
	return value / (1 << FRACTIONAL_BITS);
}

/*
std::ostream& -> Return Type
operator<< -> overloading the << operator
				<< for insertion into an output stream(e.g. std::cout, std::ofstream)
std::ostream& os -> reference to an output stream object
const Fixed &obj -> reference to the Fixed object
*/
std::ostream& operator<<(std::ostream& os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}
