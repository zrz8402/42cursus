/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:18 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/11 16:26:03 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rgb(int	first, int second, float percent, float intensity)
{
	if (first == second)
		return (first * intensity);
	return ((int)((first + (second - first) * percent) * intensity));
}

int	get_color(int x, t_point sp, t_point ep, float intensity)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = abs(x - sp.x) / abs(ep.x - sp.x);
	if (sp.reverse)
	{
		r = get_rgb((ep.color >> 16 & 0xFF), (sp.color >> 16 & 0xFF), percent, intensity);
		g = get_rgb((ep.color >> 8 & 0xFF), (sp.color >> 8 & 0xFF), percent, intensity);
		b = get_rgb((ep.color & 0xFF), (sp.color & 0xFF), percent, intensity);
	}
	else
	{
		r = get_rgb((sp.color >> 16 & 0xFF), (ep.color >> 16 & 0xFF), percent, intensity);
		g = get_rgb((sp.color >> 8 & 0xFF), (ep.color >> 8 & 0xFF), percent, intensity);
		b = get_rgb((sp.color & 0xFF), (ep.color & 0xFF), percent, intensity);
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
		// printf("(%d %d %d)", fdf->img->pixels[i], fdf->img->pixels[i + 1], fdf->img->pixels[i + 2]);
		// printf("%d\n", color);
	}
}

void	plot(t_fdf *fdf, t_point sp, t_point ep, float gradient, int steep)
{
	int		x;
	float	y;

	x = sp.x;
	y = (float)sp.y;
	//printf("%d %d (%f %d %f)\n", x, ep.x, y, steep, gradient);
	if (steep > 1)
	{
		while (x < ep.x)
		{
			put_pixel(fdf, iPartN(y), x, get_color(x, sp, ep, rfPartN(y)));
			put_pixel(fdf, iPartN(y - 1), x, get_color(x, sp, ep, fPartN(y)));
			x++;
			y += gradient;
		}
	}
	else
	{
		while (x < ep.x)
		{
			put_pixel(fdf, x, iPartN(y), get_color(x, sp, ep, rfPartN(y)));
			put_pixel(fdf, x, iPartN(y - 1), get_color(x, sp, ep, fPartN(y)));
			x++;
			y += gradient;
		}		
	}
	(void) fdf;
}

void	draw_line(t_fdf *fdf, t_point sp, t_point ep)
{
	int 	steep;
	float	gradient;

	steep = abs(ep.y - sp.y) > abs(ep.x - sp.x);
	if (steep > 1)
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
	//printf("(%d %d) (%d %d) %f\n", sp.x, sp.y, ep.x, ep.y, gradient);
	plot(fdf, sp, ep, gradient, steep);
}
