/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:12:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 12:21:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : data(NULL), size(0) {}

template <typename T>
Array<T>::Array( unsigned int n ) : data(new T[n]), size(n) {}

template <typename T>
Array<T>::Array( const Array &other ) : data(new T[other.size]), size(other.size) {
	for (unsigned int i = 0; i < size; i++) {
		data[i] = other[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=( const Array &other ) {
	if (this != &other) {
		delete[] data;
		size = other.size;
		data = new T[size];
		for (unsigned int i = 0; i < size; i++) {
			data[i] = other[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array( void ) {
	delete[] data;
}

template <typename T>
unsigned int	Array<T>::getSize( void ) const {
	return size;
}

template <typename T>
T& Array<T>::operator[]( unsigned int idx ) {
	if (idx >= size)
		throw std::out_of_range("Index out of bounds");
	return data[idx];
}

template <typename T>
const T& Array<T>::operator[]( unsigned int idx ) const {
	if (idx >= size)
		throw std::out_of_range("Index out of bounds");
	return data[idx];
}
