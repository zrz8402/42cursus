/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:59:20 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/14 18:01:27 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (fdf->camera->projection == ISO)
		mlx_put_string(fdf->mlx, "Current: ISO", x + 30, y += 20);
	else
		mlx_put_string(fdf->mlx, "Current: parallel", x + 30, y += 20);
	if (fdf->camera->zoom == 1)	
		mlx_put_string(fdf->mlx, "Minimized map.", WIDTH / 3, HEIGHT / 3);
}
