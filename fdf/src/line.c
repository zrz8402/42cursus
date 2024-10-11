/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:18 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/11 17:21:35 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(int first, int second, float perc, float intensity)
{
	if (first == second)
		return (first * intensity);
	return ((int)((first + (second - first) * perc) * intensity));
}

int	get_color(int x, t_point sp, t_point ep, float intensity)
{
	int		r;
	int		g;
	int		b;
	float	perc;

	perc = abs(x - sp.x) / abs(ep.x - sp.x);
	if (sp.reverse)
	{
		r = rgb((ep.c >> 16 & 0xFF), (sp.c >> 16 & 0xFF), perc, intensity);
		g = rgb((ep.c >> 8 & 0xFF), (sp.c >> 8 & 0xFF), perc, intensity);
		b = rgb((ep.c & 0xFF), (sp.c & 0xFF), perc, intensity);
	}
	else
	{
		r = rgb((sp.c >> 16 & 0xFF), (ep.c >> 16 & 0xFF), perc, intensity);
		g = rgb((sp.c >> 8 & 0xFF), (ep.c >> 8 & 0xFF), perc, intensity);
		b = rgb((sp.c & 0xFF), (ep.c & 0xFF), perc, intensity);
	}
	return (r << 16 | g << 8 | b);
}

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x + y * WIDTH) * 4;
		fdf->img->pixels[i] = color >> 16 & 0xFF;
		fdf->img->pixels[i + 1] = color >> 8 & 0xFF;
		fdf->img->pixels[i + 2] = color & 0xFF;
		fdf->img->pixels[i + 3] = 255;
	}
}

void	plot(t_fdf *fdf, t_point sp, t_point ep, float gradient)
{
	int		x;
	float	y;

	x = sp.x;
	y = (float)sp.y;
	if (fdf->steep > 1)
	{
		while (x < ep.x)
		{
			put_pixel(fdf, i_part(y), x, get_color(x, sp, ep, rf_part(y)));
			put_pixel(fdf, i_part(y) + 1, x, get_color(x, sp, ep, f_part(y)));
			x++;
			y += gradient;
		}
	}
	else
	{
		while (x < ep.x)
		{
			put_pixel(fdf, x, i_part(y), get_color(x, sp, ep, rf_part(y)));
			put_pixel(fdf, x, i_part(y) + 1, get_color(x, sp, ep, f_part(y)));
			x++;
			y += gradient;
		}
	}
}

void	draw_line(t_fdf *fdf, t_point sp, t_point ep)
{
	float	gradient;

	fdf->steep = abs(ep.y - sp.y) > abs(ep.x - sp.x);
	if (fdf->steep > 1)
	{
		swap(&sp.x, &sp.y);
		swap(&ep.x, &ep.y);
	}
	if (sp.x > ep.x)
	{
		swap(&sp.x, &ep.x);
		swap(&sp.y, &ep.y);
		sp.reverse = 1;
	}
	if (sp.x == ep.x)
		gradient = 1.f;
	else
		gradient = (ep.y - sp.x) / (ep.x - sp.x);
	plot(fdf, sp, ep, gradient);
}
