/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:33:08 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/15 15:42:34 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press(mlx_key_data_t keycode, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (keycode.action == MLX_PRESS)
	{
		if (keycode.key == 256)
			mlx_close_window(fdf->mlx);
		if (keycode.key == 45 || keycode.key == 333
				|| keycode.key == 62 || keycode.key == 334)
			zoom(keycode.key, fdf);
		else if (keycode.key >= 262 && keycode.key <= 265)
			move(keycode.key, fdf);
		else if ((keycode.key >= 49 && keycode.key <= 54)
					&& (keycode.key >= 321 && keycode.key <= 326))
			rotate(keycode.key, fdf);
		else if (keycode.key == 44 || keycode.key == 46)
			flatten(keycode.key, fdf);
		else if (keycode.key == 73 || keycode.key == 80)
			change_projection(keycode.key, fdf);
	}
}

void	mouse_press(mouse_key_t button, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (button == 1)
		return ;
}

void	scroll(double xdelta, double ydelta, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (ydelta > 0)
		zoom(45, fdf);
	else if (ydelta < 0)
		zoom(62, fdf);
}

void		hook_control(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, &key_press, &fdf);
}