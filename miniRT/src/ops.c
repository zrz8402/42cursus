/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:29:34 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/04 18:19:49 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

// comapre doubleing vect numbers
// if equal(< EPSILON), return true
// else, return false
bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

t_vect	add_vectors(t_vect a, t_vect b)
{
	return ((t_vect){a.x + b.x, a.y + b.y, a.z + b.z});
}

// point1 - point2: pointing from p2 to p1
// vector1 - vector2: change in direction between the two
t_vect	subtract_vectors(t_vect a, t_vect b)
{
	return ((t_vect){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vect	negate_vect(t_vect a)
{
	return ((t_vect){-a.x, -a.y, -a.z});
}

t_vect	scale_vector(t_vect a, double t)
{
	return ((t_vect){a.x * t, a.y * t, a.z * t});
}

// magnitude = 1: unit vector
double	magnitude(t_vect a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

t_vect	normalize(t_vect a)
{
	double	mag;

	mag = magnitude(a);
	return ((t_vect){a.x / mag, a.y / mag, a.z / mag});
}

// the smaller the doct product, the larger angle between the vectors
// given two unit vectors:
//		dot_procuct: cosine of the angle between them
// 		dot-product = 1: two vectors are identical
// 		dot-product = -1: two vectors vect in opposite directons
double	dot_product(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// unit vectors X, Y Z
// cross(X, Y) -> Z
// cross(Y, Z) -> X
// cross(Z, X) -> Y
// cross(Y, X) -> -Z
t_vect	cross_product(t_vect a, t_vect b)
{
	return ((t_vect){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x});
}
