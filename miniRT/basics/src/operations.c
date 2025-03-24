/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:15:21 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/24 15:44:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

// comapre floating point numbers
// if equal(< EPSILON), return true
// else, return false
bool	equal(float a, float b)
{
	if (fabsf(a - b) < EPSILON)
		return (true);
	return (false);
}

t_point	add_tuples(t_point a, t_point b)
{
	return ((t_point){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

// point1 - point2: pointing from p2 to p1
// vector1 - vector2: change in direction between the two
t_point	subtract_tuples(t_point a, t_point b)
{
	return ((t_point){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
}

t_point	negate_tuple(t_point a)
{
	return ((t_point){-a.x, -a.y, -a.z, -a.w});
}

t_point	multiply_tuple(t_point a, float t)
{
	return ((t_point){a.x * t, a.y * t, a.z * t, a.w * t});
}

t_point	divide_tuple(t_point a, float t)
{
	if (t == 0)
		return ((t_point){0, 0, 0, 0});
	return ((t_point){a.x / t, a.y / t, a.z / t, a.w / t});
}

float	magnitude(t_point a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.w, 2)));
}
