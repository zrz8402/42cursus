/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:28:21 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/15 13:16:04 by ruzhang          ###   ########.fr       */
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
		return (free_fdf(fdf), error("Error initiating camera"), fdf->camera);
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
	camera->z_divisor = 1;
	return (camera);
}

t_mouse	*init_mouse(t_fdf *fdf)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!mouse)
		return (free_fdf(fdf), error("Error initiating mouse"), fdf->mouse);
	ft_memset(mouse, 0, sizeof(t_mouse));
	return (mouse);
}

void	init_fdf(t_map *map, t_fdf *fdf)
{
	fdf->map = map;
	fdf->camera = init_camera(fdf);
	fdf->mouse = init_mouse(fdf);
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->camera)
		free(fdf->camera);
	if (fdf->mouse)
		free(fdf->mouse);
}
