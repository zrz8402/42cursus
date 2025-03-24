/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:15:21 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/24 17:01:09 by ruzhang          ###   ########.fr       */
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

// magnitude = 1: unit vector
float	magnitude(t_point a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.w, 2)));
}

t_point	normalize(t_point a)
{
	return ((t_point){a.x / magnitude(a), a.y / magnitude(a),
		a.z / magnitude(a), a.w / magnitude(a)});
}

// the smaller the doct product, the larger angle between the vectors
// given two unit vectors:
//		dot_procuct: cosine of the angle between them
// 		dot-product = 1: two vectors are identical
// 		dot-product = -1: two vectors point in opposite directons
float	dot_product(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

// unit vectors X, Y Z
// cross(X, Y) -> Z
// cross(Y, Z) -> X
// cross(Z, X) -> Y
// cross(Y, X) -> -Z
t_point	cross_product(t_point a, t_point b)
{
	return ((t_point){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		0});
}
