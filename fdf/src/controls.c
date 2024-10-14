/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:33:08 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/14 17:24:23 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press(mlx_key_data_t keycode, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (keycode.key == 256)
		mlx_terminate(fdf->mlx);
	if (keycode.key == 45 || keycode.key == 333
			|| keycode.key == 62 || keycode.key == 334)
		zoom(keycode.key, fdf);
}

void	mouse_press(mouse_key_t button, void* param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (button == 1)
		return ;
}

void	scroll(double xdelta, double ydelta, void* param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (ydelta > 0)
		zoom(45, fdf);
	else if (ydelta < 0)
		zoom(62, fdf);
}

void	set_control(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, &key_press, &fdf);
	mlx_mouse_hook(fdf->mlx, &mouse_press, &fdf);
	mlx_scroll_hook(fdf->mlx, scroll, &fdf);
}