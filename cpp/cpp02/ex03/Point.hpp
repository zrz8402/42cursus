/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:37:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/08 14:59:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point {

private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point& operator=(const Point &other);
	~Point();

	Fixed	get_x() const;
	Fixed	get_y() const;
};

#endif