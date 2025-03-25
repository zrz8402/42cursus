/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:47:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 15:14:52 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

// sphere is centered at the world origin
// from sphere center to ray origin
float	discriminant(t_sphere sphere, t_ray ray)
{
	t_point		sphere_to_ray;
	float		a;
	float		b;
	float		c;

	sphere_to_ray = subtract_tuples(ray.origin, sphere.center);
	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	return (pow(b, 2) - 4 * a * c);
}

t_intersections	intersect(t_sphere sphere, t_ray ray)
{
	t_point			sphere_to_ray;
	float			a;
	float			b;
	float			c;
	float			discriminant;
	t_intersections	intersections;

	sphere_to_ray = subtract_tuples(ray.origin, sphere.center);
	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
	{
		intersections.count = 0;
		return (intersections);
	}
	intersections.count = 2;
	intersections.i1.t = (-b - sqrt(discriminant)) / (2 * a);
	intersections.i2.t = (-b + sqrt(discriminant)) / (2 * a);
	intersections.i1.obj_id = sphere.obj_id;
	intersections.i2.obj_id = sphere.obj_id;
	return (intersections);
}
// printf("a: (%.6g)\n", a);
// printf("b: (%.6g)\n", b);
// printf("c: (%.6g)\n", c);
// printf("dicriminant: (%.6g)\n", discriminant);

// sort intersection list
// get the first non_negative intersection
// t_intersection	hit(t_intersections xs)
// {
// 	if (xs.i1.t > 0)
// 		return (xs.i1);
// 	if (xs.i2.t > 0)
// 		return (xs.i2);
// }
