/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:02:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/30 14:16:30 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// bp = (x - x2)(y - y2)
// ba = (x1 - x2)(y1 - y2)
// bp * ba = (x - x2)(y1 - y2) - (x1 - x2)(y - y2)
float	sign(Point const point, Point const p1, Point const p2) {
	return (point.get_x().toFloat() - p2.get_x().toFloat()) * (p1.get_y().toFloat() - p2.get_y().toFloat())
			- (p1.get_x().toFloat() - p2.get_x().toFloat()) * (point.get_y().toFloat() - p2.get_y().toFloat());
}

// d1 = bp * ba
// d2 = cp * cb
// d3 = ap * ac
// if all_neg || all_pos ->inside
// if one == 0, the other two will be neg + neg || pos + pos ->lies on one line
// else combination of neg and pos -> outside
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float	d1, d2, d3;
	bool	all_neg, all_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	all_neg = (d1 < 0) && (d2 < 0) && (d3 < 0);
	all_pos = (d1 > 0) && (d2 > 0) && (d3 > 0);

	return (all_neg || all_pos);
}
