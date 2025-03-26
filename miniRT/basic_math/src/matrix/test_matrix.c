/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:02:47 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 15:38:27 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

void	test_multiply_matrix(void)
{
	t_matrix	A;
	t_matrix	B;
	
	float	mA[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}};
	initialize_matrix(&A, mA);
	printf("\nmatrixA\n");
	print_matrix(A);

	float	mB[4][4] = {
		{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}};
	initialize_matrix(&B, mB);
	printf("\nmatrixB\n");
	print_matrix(B);

	printf("\nmultiply matrix\n");
	print_matrix(multiple_matrix(A, B));
}

void	test_matrix(void)
{
	printf("\n--------test matrix---------\n");
	test_multiply_matrix();
	printf("\n");
}
