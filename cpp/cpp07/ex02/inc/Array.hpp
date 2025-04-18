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

	
	// The non-const version allows modifying elements.
	T& operator[]( unsigned int idx );
	// The const version is for read-only access when the Array itself is const.
	const T& operator[]( unsigned int idx ) const;
};

/*
Why we include .tpp at the end of .hpp file?
Template implementations must be visible to the compiler at the time of instantiation.
🧩 What does that mean?
Template classes are not compiled into .o (object) files on their own.
Instead, the compiler needs to see the full implementation 
	whenever it creates a version of the template 
	for a specific type (like Array<int> or Array<std::string>).
So you can’t put the implementation only in a .cpp or .o file like with normal classes.
*/
#include "Array.tpp"

#endif