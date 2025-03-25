/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:23:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 15:08:34 by ruzhang          ###   ########.fr       */
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

typedef	enum	e_obj_id
{
	AMBIENT,	// 0
	CAMERA,		// 1
	LIGHT,		// 2
	SPHERE,		// 3
	PLANE,		// 4
	CYLINDER	// 5
}	t_obj_id;


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

typedef struct s_intersection
{
	float	t;
	int		obj_id;
}	t_intersection;

typedef struct s_intersections
{
	int					count;
	t_intersection		i1;
	t_intersection		i2;
}	t_intersections;

typedef struct s_sphere
{
	int		obj_id;		// sp
	t_point	center;
	float	diameter;
	t_color	color;
}	t_sphere;

// init.c
int	init_rt(t_rt *rt);

#endif