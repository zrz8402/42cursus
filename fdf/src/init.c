/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:28:21 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/16 18:30:49 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error("Error initiating map\n");
	map->width = 0;
	map->height = 0;
	map->num_arr = NULL;
	map->color_arr = NULL;
	map->z_min = (int)(~0U >> 1);
	map->z_max = (int)(~(~0U >> 1));
	map->z_range = 0;
	return (map);
}

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (free_fdf(fdf), error("Error initiating camera\n"), fdf->camera);
	camera->zoom = WIDTH / fdf->map->width;
	if (camera->zoom > (HEIGHT / fdf->map->height))
		camera->zoom = HEIGHT / fdf->map->height;
	camera->zoom /= 2;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->projection = ISO;
	camera->x_offset = 0;
	camera->y_offset = 0;
	if (fdf->map->z_range)
		camera->z_divisor = fdf->map->z_range;
	else if (fdf->map->z_max)
		camera->z_divisor = fdf->map->z_max;
	else
		camera->z_divisor = 1;
	return (camera);
}

void	init_fdf(t_map *map, t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF", false);
	if (!fdf->mlx)
		return (free_map(map), error("Error initiating MLX\n"));
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		return (free_map(map), mlx_terminate(fdf->mlx),
			error("Error creating image\n"));
	fdf->map = map;
	fdf->camera = init_camera(fdf);
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->camera)
		free(fdf->camera);
}
