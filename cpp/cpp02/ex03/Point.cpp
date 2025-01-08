/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:37:01 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/08 15:01:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &other) {
	*this = other;
}

Point& Point::operator=(const Point &other) {
	if (this != &other) {
		
	}
	return *this;
}

Point::~Point() {}

Fixed	Point::get_x() const {
	return x;
}

Fixed	Point::get_y() const {
	return y;
}
