/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:03:19 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/09 15:44:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main() {
	Point 	a(1.0, 1.0);
	Point	b(4.0, 1.0);
	Point	c(2.0, 4.0);

	Point	point_inside(2.0, 2.0);
	Point	point_outside(5.0, 3.0);
	Point	point_on_line(2.0, 1.0);

	std::cout << "inside the triangle" << std::endl;
	if (bsp(a, b, c, point_inside))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is not inside the triangle" << std::endl;

	std::cout << "\noutside the triangle" << std::endl;
	if (bsp(a, b, c, point_outside))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is not inside the triangle" << std::endl;

	std::cout << "\non one of the line" << std::endl;
	if (bsp(a, b, c, point_on_line))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is not inside the triangle" << std::endl;
	return 0;
}