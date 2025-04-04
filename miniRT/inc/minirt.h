/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:23:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/04 18:23:46 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 30
# define HEIGHT 20
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
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}	t_vect;

typedef struct s_ray
{
	t_vect	origin;
	t_vect	direction;
}	t_ray;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
}	t_quadratic;

/*
point:
represent the coordinates of the intersection point where the ray intersects the object
The point in 3D space where the ray hits the surface of the object is crucial because it tells us where the intersection occurs. This point is typically calculated by scaling the ray's direction vector by the intersection distance (e.g., t) and adding it to the ray's origin.

normal;
represent the surface normal at the point of intersection.
he surface normal is a vector that is perpendicular to the surface of the object at the point of intersection. For a sphere, this normal would point outward from the center of the sphere at the point of intersection. The normal is important for various tasks, like shading, lighting, and calculating how light reflects off the surface.

distance:
represent the distance from the ray’s origin to the intersection point.
The distance is important because it tells you how far along the ray’s path the intersection occurs. It can be used for sorting intersections or determining which intersection happens first (if there are multiple intersections with different objects). In ray tracing, you generally want to know which object the ray hits first

*solid:
a pointer to the actual object that the ray intersects (such as a sphere, plane, or other geometric object).
The solid field holds a reference to the object that was hit by the ray. Since this is a void *, it's a generic pointer that can point to any object. This allows you to store any type of object (e.g., a sphere, a plane, etc.) without having to hardcode the type into the data structure. This is useful in ray tracing or intersection handling when you have many different types of objects and need to refer to them generically.
*/
typedef struct s_intersect
{
	t_vect				point;
	t_vect				normal;
	double				distance;
	void				*solid;
	double	t1;
	double	t2;
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_sphere
{
	// int		obj_id;		// sp
	t_vect	center;
	double	diameter;
	// t_color	color;
}	t_sphere;

// init.c
int	init_rt(t_rt *rt);

#endif