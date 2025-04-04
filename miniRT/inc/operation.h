/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:42:01 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/04 18:24:43 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef OPERATION_H
# define OPERATION_H

# define EPSILON 1e-6

# ifndef PI
#  define PI 3.14159265358979323846
# endif

#include "minirt.h"

// operations.c
bool	equal(double a, double b);

t_vect	add_vectors(t_vect a, t_vect b);
t_vect	subtract_vectors(t_vect a, t_vect b);
t_vect	negate_vect(t_vect a);
t_vect	scale_vector(t_vect a, double t);
double	magnitude(t_vect a);
t_vect	normalize(t_vect a);
double	dot_product(t_vect a, t_vect b);
t_vect	cross_product(t_vect a, t_vect b);

// ray.c
t_ray	create_ray(t_vect origin, t_vect direction);
t_vect	ray_pos(t_ray ray, double t);

// intersect.c
void		calculate_quadratic(t_sphere sphere, t_ray ray, t_quadratic *q);
t_intersect	*append_intersect(t_sphere sphere, t_ray ray);
t_intersect *create_intersect(t_sphere sphere, t_ray ray, double t);
void		add_intersect(t_intersect **intersection, t_sphere sphere, t_ray ray, double t);

// transformation.c
void	translate(t_vect *p, t_vect trans);
void	scale(t_vect *p, t_vect trans);
void	rotate_x(t_vect *p, double angle);
void	rotate_y(t_vect *p, double angle);
void	rotate_z(t_vect *p, double angle);
void	shearing(t_vect *p, int *trans);

t_vect	translation(t_vect p, t_vect trans);
t_vect	scaling(t_vect p, t_vect trans);
t_vect	rotation_x(t_vect p, double angle);
t_vect	rotation_y(t_vect p, double angle);
t_vect	rotation_z(t_vect p, double angle);


t_ray	create_ray(t_vect origin, t_vect direction);
t_vect	position(t_ray ray, double t);
double	discriminant(t_sphere sphere, t_ray ray);


#endif