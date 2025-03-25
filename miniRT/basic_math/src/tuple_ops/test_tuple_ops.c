/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuple_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:31:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 11:14:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	test_tuple_ops(void)
{
	printf("\n----test basic tuple operations----\n");
	t_point	a;
	t_point	b;
	t_point	result;

	a = (t_point){3, -2, 5, 1};
	b = (t_point){-2, 3, 1, 1};
	result = add_tuples(a, b);
	printf("add_tuples: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);

	a = (t_point){3, 2, 1, 1};
	b = (t_point){5, 6, 7, 1};
	result = subtract_tuples(a, b);
	printf("subtract_tuples: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);

	a = (t_point){1, -2, 3, -4};
	result = negate_tuple(a);
	printf("negate_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	a = (t_point){1, -2, 3, -4};
	result = multiply_tuple(a, 3.5);
	printf("multiply_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	result = multiply_tuple(a, 0.5);
	printf("multiply_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	a = (t_point){1, -2, 3, -4};
	result = divide_tuple(a, 2);
	printf("divide_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	a = (t_point){1, 0, 0, 0};
	printf("magnitude: %.6g\n", magnitude(a));
	a = (t_point){0, 1, 0, 0};
	printf("magnitude: %.6g\n", magnitude(a));
	a = (t_point){1, 2, 3, 0};
	printf("magnitude: %.6g\n", magnitude(a));
	a = (t_point){-1, -2, -3, 0};
	printf("magnitude: %.6g\n", magnitude(a));

	a = (t_point){4, 0, 0, 0};
	result = normalize(a);
	printf("normalize: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);
	a = (t_point){1, 2, 3, 0};
	result = normalize(a);
	printf("normalize: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);
	printf("magnitude: %.6g\n", magnitude(normalize(a)));

	a = (t_point){1, 2, 3, 0};
	b = (t_point){2, 3, 4, 0};
	printf("dot product: %.6g\n", dot_product(a, b));

	a = (t_point){1, 2, 3, 0};
	b = (t_point){2, 3, 4, 0};
	result = cross_product(a, b);
	printf("cross product: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);
	result = cross_product(b, a);
	printf("cross product: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);

	printf("\n");
}

typedef struct s_projectile
{
	t_point	position;	// point
	t_point	velocity;	// vector
}	t_projectile;

typedef struct s_environment
{
	t_point	gravity;	// point
	t_point	wind;		// vector
}	t_environment;

t_projectile	tick(t_environment env, t_projectile proj)
{
	t_point	position;
	t_point	velocity;

	position = add_tuples(proj.position, proj.velocity);
	velocity = add_tuples(add_tuples(proj.velocity, env.gravity), env.wind);
	return ((t_projectile){position, velocity});
}

void	test_overall_tuples_ops(void)
{
	int				i = 0;
	t_point			position = {0, 1, 0, 1};
	t_point			velocity = {1, 1, 0, 0};
	t_projectile	proj = {position, normalize(velocity)};
	t_point			gravity = {0, -0.1, 0, 1};
	t_point			wind = {-0.01, 0, 0, 0};
	t_environment	env = {gravity, wind};

	printf("original proj: (%.6g, %.6g, %.6g)\n", 
		proj.position.x,
		proj.position.y,
		proj.position.z);
	while (proj.position.y > 0)
	{
		i++;
		proj = tick(env, proj);
		printf("After %d tick(s): (%.6g, %.6g, %.6g)\n", i, proj.position.x, proj.position.y, proj.position.z);
	}
	printf("It takes %d ticks to hit the ground\n", i);
}
