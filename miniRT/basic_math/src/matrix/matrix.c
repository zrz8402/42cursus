/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:17:23 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 15:21:26 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	initialize_matrix(t_matrix *matrix, float values[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			matrix->m[i][j] = values[i][j];
	}
}

void	print_matrix(t_matrix matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%.6g ", matrix.m[i][j]);
		printf("\n");
	}
}

t_matrix	multiple_matrix(t_matrix A, t_matrix B)
{
	int			i;
	int			j;
	int			k;
	t_matrix	result;

	i = -1;
	memset(&result, 0, sizeof(t_matrix));
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				result.m[i][j] += A.m[i][k] * B.m[k][j];
		}
	}
	return (result);
}

