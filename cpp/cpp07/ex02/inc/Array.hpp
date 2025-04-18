/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:12:28 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 12:20:09 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

template <typename T>

class Array {

private:
	T*				data;
	unsigned int	size;

public:
	Array( void );
	Array( unsigned int n );
	Array( const Array &other );
	Array& operator=( const Array &other );
	~Array( void );

	unsigned int	getSize( void ) const;

	T& operator[]( unsigned int idx );
	const T& operator[]( unsigned int idx ) const;
};

#include "Array.tpp"

#endif