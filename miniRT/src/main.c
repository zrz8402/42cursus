/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:22:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/23 14:27:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_rt(t_rt *rt)
{
	rt->mlx = mlx_init(WIDTH, HEIGHT, "", false);
	if (rt->mlx)
	{
		perror("Error initiating mlx\n");
		return ;
	}
	rt->img = mlx_new_image(rt->mlx, WIDTH, HEIGHT);
	if (rt->img)
	{
		mlx_terminate(rt->mlx);
		perror("Error creating image\n");
		return ;
	}
}

int	main(void)
{
	t_rt	rt;

	init_rt(&rt);
}
