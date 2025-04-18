/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:55:26 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 16:52:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : capacity(10) {}

Span::Span( unsigned int n ) : capacity(n) {}

Span::Span( const Span &other ) : capacity(other.capacity), elements(other.elements) {}

Span& Span::operator=( const Span &other ) {
	if (this != &other) {
		capacity = other.capacity;
		elements = other.elements;
	}
	return *this;
}

Span::~Span( void ) {}

/*
`std::length_error`
- **Best fit** for "container is full" scenarios.
- Specifically designed for exceeding allowed size limits.

`std::logic_error`
- More **generic** than `length_error`.
- Use only if no specific derived type fits.

`std::overflow_error`
- Intended for **numeric overflows**
*/
void	Span::addNumber( int n ) {
	if (elements.size() >= capacity) {
		throw std::length_error("Cannot add more numbers: max size reached.");
	}
	elements.push_back(n);
}

int	Span::shortestSpan( void ) const {
	if (elements.size() < 2) {
		throw std::logic_error("Not enough elements to calculate a span");
	}

	std::vector<int>	tmp = elements;
	std::sort(tmp.begin(), tmp.end());

	int	minSpan = INT_MAX;
	for (size_t i = 1; i < tmp.size(); i++) {
		int	diff = tmp[i] - tmp[i - 1];
		if (diff < minSpan) {
			minSpan = diff;
		}
	}
	return minSpan;
}

int	Span::longestSpan( void ) const {
	if (elements.size() < 2) {
		throw std::logic_error("Not enough elements to calculate a span");
	}

	// min_element/max_element
	// return: Iterator referencing the first instance of the smallest/largest value.
	int	min = *std::min_element(elements.begin(), elements.end());
	int	max = *std::max_element(elements.begin(), elements.end());

	return max - min;
}

void	Span::printElements( void ) const {
	std::copy(elements.begin(), elements.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
