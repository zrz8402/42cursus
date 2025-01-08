/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:10:19 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/08 14:34:30 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {

private:
	int					value;
	static const int	FRACTIONAL_BITS = 8;

public:
	Fixed();
	Fixed( const int value );
	Fixed& operator=(const Fixed &other );
	~Fixed();
	
	Fixed( const float value );
	Fixed( const Fixed &other );
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool operator<(const Fixed &other ) const;
	bool operator<=(const Fixed &other ) const;
	bool operator>(const Fixed &other ) const;
	bool operator>=(const Fixed &other ) const;
	bool operator==(const Fixed &other ) const;
	bool operator!=(const Fixed &other ) const;

	Fixed operator+(const Fixed &other ) const ;
	Fixed operator-(const Fixed &other ) const ;
	Fixed operator*(const Fixed &other ) const ;
	Fixed operator/(const Fixed &other ) const ;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed &obj);

#endif