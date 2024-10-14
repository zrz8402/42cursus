/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:44:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/14 15:49:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	default_color(t_map *map, int altitude)
{
	int		rgb;
	float	percent;

	if (map->z_range == 0)
		percent = 0.f;
	else
		percent = (float)altitude / (map->z_range);
	rgb = (255 * percent);
	return (rgb << 16 | rgb << 8 | rgb);
}

t_point	point(t_map *map, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map->num_arr[y][x];
	if (map->color_arr[y][x] < 0)
		point.c = default_color(map, point.z);
	else
		point.c = map->color_arr[y][x];
	point.reverse = 0;
	return (point);
}

t_point	project(t_fdf *fdf, t_point point)
{
	int	x;
	int	y;

	point.x *= fdf->camera->zoom;
	point.y *= fdf->camera->zoom;
	point.z *= fdf->camera->zoom;
	rotate_x(&point.y, &point.z, fdf->camera->alpha);
	rotate_y(&point.x, &point.z, fdf->camera->beta);
	rotate_z(&point.x, &point.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		iso(&point.x, &point.y, point.z);
	point.x += fdf->camera->x_offset;
	point.y += fdf->camera->y_offset;
	return (point);
}

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height && y >= 0)
	{
		x = 0;
		while (x < map->width && x >= 0)
		{
			if (x != map->width - 1)
				draw_line(fdf, project(fdf, point(map, x, y)),
					project(fdf, point(map, x + 1, y)));
			if (y != map->height - 1)
				draw_line(fdf, project(fdf, point(map, x, y)),
					project(fdf, point(map, x, y + 1)));
			x++;
		}
		y++;
	}
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
}
