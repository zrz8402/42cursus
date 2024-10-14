/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:28:21 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/13 18:24:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error("Error initiating map.");
	map->width = 0;
	map->height = 0;
	map->num_arr = NULL;
	map->color_arr = NULL;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	map->z_range = 0;
	return (map);
}

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
	{
		mlx_delete_image(fdf->mlx, fdf->img);
		mlx_terminate(fdf->mlx);
		free_map(fdf->map);
		free(fdf);
		error("Error initiating camera");
	}
	//camera->zoom = WIDTH / fdf->map->width / 2;
	camera->zoom = 10;
	camera->alpha = 0;
	camera->belta = 0;
	camera->gamma = 0;
	camera->projection = ISO;
	// camera->x_offset = 1;
	// camera->y_offset = 1;
	camera->x_offset = (WIDTH - fdf->map->width * camera->zoom) / 2;
	camera->y_offset = (HEIGHT - fdf->map->height * camera->zoom) / 2;
	return (camera);
}

t_mouse	*init_mouse(t_fdf *fdf)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!mouse)
	{
		mlx_delete_image(fdf->mlx, fdf->img);
		mlx_terminate(fdf->mlx);
		free_map(fdf->map);
		free(fdf->camera);
		free(fdf);
		error("Error initiating mouse");
	}
	ft_memset(mouse, 0, sizeof(t_mouse));
	return (mouse);
}

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (free_map(map), error("Error initiating FDF"), fdf);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF", false);
	if (!fdf->mlx)
		return (free_map(map), free(fdf), error("Error initiating MLX"), fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
	{
		mlx_terminate(fdf->mlx);
		free_map(fdf->map);
		free(fdf);
		error("Error initiating image");
	}
	fdf->map = map;
	fdf->camera = init_camera(fdf);
	fdf->mouse = init_mouse(fdf);
	return (fdf);
}
