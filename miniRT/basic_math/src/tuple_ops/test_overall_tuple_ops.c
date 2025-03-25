/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_overall_tuple_ops.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:19:50 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 13:25:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

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
