/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:18 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/12 13:55:40 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(int first, int second, float perc, float intensity)
{
	if (first == second)
		return (first * intensity);
	return ((int)((first + (second - first) * perc) * intensity));
}

int	get_c(int x, t_point sp, t_point ep, float intensity)
{
	int		r;
	int		g;
	int		b;
	int		a;
	float	perc;

	a = 255;
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
	a *= intensity;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	plot(t_fdf *fdf, t_point sp, t_point ep, float gradient)
{
	int		x;
	float	y;

	x = sp.x;
	y = (float)sp.y;
	if (fdf->steep)
	{
		while (x <= ep.x)
		{
			mlx_put_pixel(fdf->img, ipt(y), x, get_c(x, sp, ep, rfpt(y)));
			mlx_put_pixel(fdf->img, ipt(y) + 1, x, get_c(x, sp, ep, fpt(y)));
			x++;
			y += gradient;
		}
	}
	else
	{
		while (x <= ep.x)
		{
			mlx_put_pixel(fdf->img, x, ipt(y), get_c(x, sp, ep, rfpt(y)));
			mlx_put_pixel(fdf->img, x, ipt(y) + 1, get_c(x, sp, ep, fpt(y)));
			x++;
			y += gradient;
		}
	}
}

void	draw_line(t_fdf *fdf, t_point sp, t_point ep)
{
	float	gradient;

	fdf->steep = abs(ep.y - sp.y) > abs(ep.x - sp.x);
	if (fdf->steep)
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
		gradient = (ep.y - sp.y) / (ep.x - sp.x);
	plot(fdf, sp, ep, gradient);
}
