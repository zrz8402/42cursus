/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:44:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/11 17:20:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	point(t_map *map, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = map->num_arr[y][x];
	point.c = map->color_arr[y][x];
	return (point);
}

void	instruction(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 30;
	y = 0;
	mlx_put_string(fdf->mlx, "Instructions", x, y += 20);
	mlx_put_string(fdf->mlx, "Zoom:", x, y += 20);
	mlx_put_string(fdf->mlx, "Move", x, y += 20);
	mlx_put_string(fdf->mlx, "Flatten", x, y += 20);
	mlx_put_string(fdf->mlx, "Rotate", x, y += 20);
	mlx_put_string(fdf->mlx, "x-axis", x + 30, y += 20);
	mlx_put_string(fdf->mlx, "y-axis", x + 30, y += 20);
	mlx_put_string(fdf->mlx, "z-axis", x + 30, y += 20);
	mlx_put_string(fdf->mlx, "Projection:", x, y += 20);
	mlx_put_string(fdf->mlx, "ISO: I key", x + 30, y += 20);
	mlx_put_string(fdf->mlx, "Parallel: P Key", x + 30, y += 20);
}

void	background(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < HEIGHT * WIDTH * 4)
	{
		fdf->img->pixels[i] = 0;
		fdf->img->pixels[i + 1] = 0;
		fdf->img->pixels[i + 2] = 0;
		fdf->img->pixels[i + 3] = 255;
		i += 4;
	}
}

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	background(fdf);
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
	instruction(fdf);
	(void) map;
}
