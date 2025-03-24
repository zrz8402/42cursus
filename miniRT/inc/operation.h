/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:42:01 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/24 15:40:50 by ruzhang          ###   ########.fr       */
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



// test.c
void	test_tuple_ops(void);
void	test_creating_ray(void);

#endif