/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:23:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 13:17:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1280
# define HEIGHT 720
# define BPP sizeof(int32_t)

# include "include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_rt
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_rt;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	w; // 1 for point, 0 for vector
}	t_point;

typedef struct s_ray
{
	t_point	origin;		// 1
	t_point	direction;	// 0
}	t_ray;

typedef struct s_intersect
{
	int		count;
	float	t1;
	float	t2;
}	t_intersect;

typedef struct s_sphere
{
	int		id;			// sp
	t_point	center;
	float	diameter;
	t_color	color;
}	t_sphere;

// init.c
int	init_rt(t_rt *rt);

#endif