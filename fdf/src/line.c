/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:18 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/15 14:20:41 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(int first, int second, float perc, float intensity)
{
	if (first == second)
		return (first * intensity);
	return ((int)((first + (second - first) * perc) * intensity));
}

uint32_t	get_c(int x, t_point sp, t_point ep, float intensity)
{
	int		r;
	int		g;
	int		b;
	int		a;
	float	perc;

	a = 255;
	perc = (float)abs(x - sp.x) / abs(ep.x - sp.x);
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

void	put_pixel(t_fdf *fdf, int x, int y, uint32_t color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x + y * WIDTH) * 4;
		fdf->img->pixels[i] = color >> 24 & 0xFF;
		fdf->img->pixels[i + 1] = color >> 16 & 0xFF;
		fdf->img->pixels[i + 2] = color >> 8 & 0xFF;
		fdf->img->pixels[i +3] = color & 0xFF;
	}
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
			put_pixel(fdf, ipt(y), x, get_c(x, sp, ep, rfpt(y)));
			put_pixel(fdf, ipt(y) + 1, x, get_c(x, sp, ep, fpt(y)));
			x++;
			y += gradient;
		}
	}
	else
	{
		while (x <= ep.x)
		{
			put_pixel(fdf, x, ipt(y), get_c(x, sp, ep, rfpt(y)));
			put_pixel(fdf, x, ipt(y) + 1, get_c(x, sp, ep, fpt(y)));
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
		gradient = (float)(ep.y - sp.y) / (ep.x - sp.x);
	plot(fdf, sp, ep, gradient);
}
