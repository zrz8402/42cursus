/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:47:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 13:08:03 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

// sphere is centered at the world origin
// from sphere center to ray origin
float	discriminant(t_ray ray, t_sphere sphere)
{
	t_point	sphere_to_ray;
	float	a;
	float	b;
	float	c;

	sphere_to_ray = subtract_tuples(ray.origin, sphere.center);
	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	return (pow(b, 2) - 4 * a * c);
}
