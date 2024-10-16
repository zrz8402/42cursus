/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:48:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/15 19:14:06 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>


int32_t	main(int ac, char **av)
{
	t_fdf	fdf;
	t_map	*map;

	if (ac < 2)
		error("No arguement");
	if (ac > 2)
		error("Too many arguements");
	map = get_map(av[1]);
	init_fdf(map, &fdf);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF", false);
	if (!fdf.mlx)
		error("Error initiating MLX");
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	if (!fdf.img)
		error("Error creating image");
	draw(map, &fdf);
	mlx_key_hook(fdf.mlx, &key_press, &fdf);
	// mlx_mouse_hook(fdf.mlx, &mouse_press, &fdf);
	mlx_scroll_hook(fdf.mlx, &scroll, &fdf);
	mlx_loop(fdf.mlx);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	free_fdf(&fdf);
}
