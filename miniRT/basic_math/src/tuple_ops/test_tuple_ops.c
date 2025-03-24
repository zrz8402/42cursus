/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:31:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/24 17:05:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	test_tuple_ops(void)
{
	printf("\n----test basic tuple operations----\n");
	t_point	a;
	t_point	b;
	t_point	result;

	a = (t_point){3, -2, 5, 1};
	b = (t_point){-2, 3, 1, 1};
	result = add_tuples(a, b);
	printf("add_tuples: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);

	a = (t_point){3, 2, 1, 1};
	b = (t_point){5, 6, 7, 1};
	result = subtract_tuples(a, b);
	printf("subtract_tuples: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);

	a = (t_point){1, -2, 3, -4};
	result = negate_tuple(a);
	printf("negate_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	a = (t_point){1, -2, 3, -4};
	result = multiply_tuple(a, 3.5);
	printf("multiply_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	result = multiply_tuple(a, 0.5);
	printf("multiply_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	a = (t_point){1, -2, 3, -4};
	result = divide_tuple(a, 2);
	printf("divide_tuple: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);

	a = (t_point){1, 0, 0, 0};
	printf("magnitude: %.6g\n", magnitude(a));
	a = (t_point){0, 1, 0, 0};
	printf("magnitude: %.6g\n", magnitude(a));
	a = (t_point){1, 2, 3, 0};
	printf("magnitude: %.6g\n", magnitude(a));
	a = (t_point){-1, -2, -3, 0};
	printf("magnitude: %.6g\n", magnitude(a));

	a = (t_point){4, 0, 0, 0};
	result = normalize(a);
	printf("normalize: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);
	a = (t_point){1, 2, 3, 0};
	result = normalize(a);
	printf("normalize: (%.6g, %.6g, %.6g, %.6g)\n", result.x, result.y, result.z, result.w);
	printf("magnitude: %.6g\n", magnitude(normalize(a)));

	a = (t_point){1, 2, 3, 0};
	b = (t_point){2, 3, 4, 0};
	printf("dot product: %.6g\n", dot_product(a, b));

	a = (t_point){1, 2, 3, 0};
	b = (t_point){2, 3, 4, 0};
	result = cross_product(a, b);
	printf("cross product: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);
	result = cross_product(b, a);
	printf("cross product: (%.6g, %.6g, %.6g)\n", result.x, result.y, result.z);

	printf("\n");
}

void	test_all_tuples_ops(void)
{
	
}
