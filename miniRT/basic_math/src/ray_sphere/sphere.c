/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:47:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 14:20:46 by ruzhang          ###   ########.fr       */
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

t_intersect	intersect(t_sphere sphere, t_ray ray)
{
	t_point		sphere_to_ray;
	float		a;
	float		b;
	float		c;
	float		discriminant;
	t_intersect	intersect;

	sphere_to_ray = subtract_tuples(ray.origin, sphere.center);
	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
	{
		intersect.count = 0;
		return (intersect);
	}
	if (discriminant == 0)
		intersect.count = 1;
	else
		intersect.count = 2;
	intersect.t1 = (-b - sqrt(discriminant)) / (2 * a);
	intersect.t2 = (-b + sqrt(discriminant)) / (2 * a);
	return (intersect);
}
// printf("a: (%.6g)\n", a);
// printf("b: (%.6g)\n", b);
// printf("c: (%.6g)\n", c);
// printf("dicriminant: (%.6g)\n", discriminant);
