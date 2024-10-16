/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:01:49 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/15 18:41:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == 45 || key == 333)
		fdf->camera->zoom--;
	else if (key == 61 || key == 334)
		fdf->camera->zoom++;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf->map, fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == 262)
		fdf->camera->x_offset++;
	else if (key == 263)
		fdf->camera->x_offset--;
	else if (key == 264)
		fdf->camera->y_offset++;
	else
		fdf->camera->y_offset--;
	draw(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == 49)
		fdf->camera->alpha += 0.5;
	else if (key == 50)
		fdf->camera->alpha -= 0.5;
	else if (key == 51)
		fdf->camera->beta += 0.5;
	else if (key == 52)
		fdf->camera->beta -= 0.5;
	else if (key == 53)
		fdf->camera->gamma += 0.5;
	else
		fdf->camera->gamma -= 0.5;
	draw(fdf->map, fdf);
}

void	flatten(int key, t_fdf *fdf)
{
	if (key == 44)
		fdf->camera->z_divisor += 0.1;
	else
		fdf->camera->z_divisor -= 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf->map, fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	if (key == 73)
		fdf->camera->projection = ISO;
	else
	{
		fdf->camera->alpha = 0;
		fdf->camera->beta = 0;
		fdf->camera->gamma = 0;
		fdf->camera->projection = PARALLEL;
	}
	draw(fdf->map, fdf);
}