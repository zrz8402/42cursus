/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:42:01 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/25 12:46:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef OPERATION_H
# define OPERATION_H

# define EPSILON 0.00001

#include "minirt.h"

// operation.c
bool	equal(float a, float b);
t_point	add_tuples(t_point a, t_point b);
t_point	subtract_tuples(t_point a, t_point b);
t_point	negate_tuple(t_point a);
t_point	multiply_tuple(t_point a, float t);
t_point	divide_tuple(t_point a, float t);
float	magnitude(t_point a);
t_point	normalize(t_point a);
float	dot_product(t_point a, t_point b);
t_point	cross_product(t_point a, t_point b);

// test_tuple_ops.c
void	test_tuple_ops(void);
void	test_overall_tuples_ops(void);

// matrix.c



// ray_sphere
t_ray	create_ray(t_point origin, t_point direction);
t_point	position(t_ray ray, float t);
void	test_ray_sphere(void);

#endif