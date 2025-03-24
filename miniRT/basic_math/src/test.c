/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:31:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/24 17:05:02 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	test_creating_ray(void)
{
	printf("\n--------test creating ray---------\n");
	t_point	origin;
	t_point	direction;
	t_ray	ray;

	origin = (t_point){2, 3, 4, 1};
	direction = (t_point){4, 5, 6, 0};
	ray.origin = origin;
	ray.direction = direction;
	printf("origin: (%.6g, %.6g, %.6g)\n", ray.origin.x, ray.origin.y, ray.origin.z);
	printf("direction: (%.6g, %.6g, %.6g)\n", ray.direction.x, ray.direction.y, ray.direction.z);
	printf("\n");
}
