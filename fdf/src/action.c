/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:01:49 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/14 16:12:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == 45 || key == 333)
		fdf->camera->zoom++;
	else if (key == 62 || key == 334)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf->map, fdf);
	if (fdf->camera->zoom == 1)	
		mlx_put_string(fdf->mlx, "Minimized map.", WIDTH / 3, HEIGHT / 3);
}