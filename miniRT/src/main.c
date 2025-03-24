/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:22:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/24 11:18:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_rt	rt;

	if (init_rt(&rt) < 0)
		return (EXIT_FAILURE);
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
			mlx_put_pixel(rt.img, i, j, 0xFF0000FF);
	}
	// memset(rt.img->pixels, 255, rt.img->width * rt.img->height * BPP);
	mlx_image_to_window(rt.mlx, rt.img, 0, 0);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	return (0);
}
