/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:31:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 13:25:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	test_create_ray(void)
{
	t_point	origin;
	t_point	direction;
	t_ray	ray;

	origin = (t_point){2, 3, 4, 1};
	direction = (t_point){4, 5, 6, 0};
	ray = create_ray(origin, direction);
	printf("origin: (%.6g, %.6g, %.6g)\n", ray.origin.x, ray.origin.y, ray.origin.z);
	printf("direction: (%.6g, %.6g, %.6g)\n", ray.direction.x, ray.direction.y, ray.direction.z);
}

void	test_position(void)
{
	t_point	origin;
	t_point	direction;
	t_ray	ray;

	origin = (t_point){2, 3, 4, 1};
	direction = (t_point){1, 0, 0, 0};
	ray = create_ray(origin, direction);

	float	t = 0;
	t_point	pos = position(ray, t);
	printf("position: (%.6g, %.6g, %.6g)\n", pos.x, pos.y, pos.z);

	t = 1;
	pos = position(ray, t);
	printf("position: (%.6g, %.6g, %.6g)\n", pos.x, pos.y, pos.z);

	t = -1;
	pos = position(ray, t);
	printf("position: (%.6g, %.6g, %.6g)\n", pos.x, pos.y, pos.z);

	t = 2.5;
	pos = position(ray, t);
	printf("position: (%.6g, %.6g, %.6g)\n", pos.x, pos.y, pos.z);
}

void	test_ray_sphere(void)
{
	printf("\n--------test ray_sphere---------\n");
	test_create_ray();
	test_position();
	printf("\n");
}
