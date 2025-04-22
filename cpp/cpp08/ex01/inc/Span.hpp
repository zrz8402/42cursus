/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:11:39 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/22 15:08:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <iterator>
#include <iostream>

class Span {

private:
	unsigned int		capacity;
	std::vector<int>	elements;

public:
	Span( void );
	Span( unsigned int n );
	Span( const Span &other );
	Span& operator=( const Span &other );
	~Span( void );

	void	addNumber( int n );

	template <typename T>
	void	addMultipleNum( T begin, T end ) {
		if (static_cast<unsigned int>(std::distance(begin, end)) > (capacity - elements.size())) {
			throw std::length_error("Not enough space.");
		}
		elements.insert(elements.end(), begin, end);
	}

	int		shortestSpan( void ) const;
	int		longestSpan( void ) const;

	void	printElements( void ) const;
};

#endif