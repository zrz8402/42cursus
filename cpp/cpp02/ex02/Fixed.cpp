/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:04:07 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 14:07:19 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed( const Fixed &other ) : value(other.value) {}

Fixed& Fixed::operator=(const Fixed &other ) {
	if (this != &other)
		value = other.value;
	return *this;
}

Fixed::~Fixed() {}

int	Fixed::getRawBits( void ) const {
	return value;
}

void	Fixed::setRawBits( int const raw ) {
	value = raw;
}

Fixed::Fixed( const int value ) : value(value << FRACTIONAL_BITS) {}

Fixed::Fixed( const float value ) : value(roundf(value * (1 << FRACTIONAL_BITS))) {}

float	Fixed::toFloat( void ) const{
	return (float)value / (1 << FRACTIONAL_BITS);
}

int		Fixed::toInt( void ) const{
	return value / (1 << FRACTIONAL_BITS);
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed &other ) const {
	return this->value < other.value;
}

bool Fixed::operator<=(const Fixed &other ) const {
	return this->value <= other.value;
}

bool Fixed::operator>(const Fixed &other ) const {
	return this->value > other.value;
}

bool Fixed::operator>=(const Fixed &other ) const {
	return this->value >= other.value;
}

bool Fixed::operator==(const Fixed &other ) const {
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other ) const {
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other ) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other ) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other ) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other ) const {
	if (std::abs(other.toFloat()) < EPSILON) {
		std::cerr << "Error: Division by zero or near-zero value." << std::endl;
		return Fixed(0);
	} else {
		return Fixed(this->toFloat() / other.toFloat());
	}	
}

// pre-increment ++a
Fixed& Fixed::operator++() {
	++value;
	return *this;
}

// post-increment a++
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	value++;
	return tmp;
}

Fixed& Fixed::operator--() {
	--value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	value--;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
