/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:33:08 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/13 16:11:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press(mlx_key_data_t keycode, t_fdf *fdf)
{
	// if (keycode.key == )
}

void	mouse_press(mouse_key_t button, void* param)
{
	
}

void	scroll(double xdelta, double ydelta, void* param)
{
	if (ydelta > 0)
		zoom();
	else if (ydelta < 0)
		zoom();
}

void	close_win(mlx_key_data_t keycode, t_fdf *fdf)
{
	// 	MLX_KEY_ESCAPE = 256
	if (keycode.key = 256)
	{
		mlx_delete_image(fdf->mlx, fdf->img);
		mlx_terminate(fdf->mlx);
		free_map(fdf->map);
		free(fdf);
		exit(1);
	}
}

void	set_control(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, key_press, &fdf);
	mlx_mouse_hook(fdf->mlx, mouse_press, &fdf);
	mlx_scroll_hook(fdf->mlx, scroll, &fdf);
	mlx_key_hook(fdf->mlx, close_win, &fdf);
	mlx_close_window(fdf->mlx);
}