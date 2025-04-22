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


	void	addMultipleNum( std::vector<int>::iterator begin, std::vector<int>::iterator end  );

	int		shortestSpan( void ) const;
	int		longestSpan( void ) const;

	void	printElements( void ) const;
};

#endif