/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:44:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/11 14:03:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	point(t_map *map, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map->num_arr[y][x];
	point.color = map->color_arr[y][x];
	//printf("point:%d %d %d %d\n", point.x, point.y, point.z, point.color);
	return (point);
}

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(fdf, point(map, x, y), point(map, x + 1, y));
			if (y < map->height - 1)
				draw_line(fdf, point(map, x, y), point(map, x, y + 1));
			x++;
		}
		y++;
	}
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	(void) fdf;
}
