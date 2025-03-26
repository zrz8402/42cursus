/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:38:56 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 13:56:43 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	test_intersect(void)
{
	t_point			origin;
	t_point			direction;
	t_ray			ray;
	t_sphere		sphere;
	t_intersections	xs;

	origin = (t_point){0, 0, 5, 1};
	direction = (t_point){0, 0, 1, 0};
	ray = create_ray(origin, direction);
	sphere.obj_id = SPHERE;
	sphere.center = (t_point){0, 0, 0, 1};
	xs.count = 0;
	xs = intersect(sphere, ray);
	if (xs.count == 0)
		printf("No intersections\n");
	else
	{
		printf("count: %d, t1: %.6g, t2: %.6g\n", xs.count, xs.i1.t, xs.i2.t);
		printf("t1.obj_id: %d, t2.obj_id: %d\n", xs.i1.obj_id, xs.i2.obj_id);
	}
}

void	test_intersection(void)
{
	test_intersect();
	printf("\n");
}
