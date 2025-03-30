/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:10:19 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 13:12:56 by ruzhang          ###   ########.fr       */
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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
	Fixed( const float value );
	Fixed( const Fixed &other );
	
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &obj);

#endif