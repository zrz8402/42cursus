/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:41:09 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/27 14:21:56 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_lis_prev(int *arr, int *lis, int *prev, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	get_max(int *lis, int n, int *max_len, int *max_index)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (*max_len < lis[i])
		{
			*max_len = lis[i];
			*max_index = i;
		}
		i++;
	}
}
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int	*get_indices(int *arr, int *lis, int *prev, int n)
{
	int	i;
	int	max_len;
	int max_index;
	int	*indices;

	max_len = 1;
	max_index = 0;
	get_max(lis, n, &max_len, &max_index);
	indices = (int *)malloc(max_len * sizeof(int));
	i = max_len - 1;
    while (max_index != -1)
	{
        indices[i] = max_index;
        max_index = prev[max_index];
        i--;
    }
	printf("\n(max len%d)\n", max_len);
	print_array(indices, max_len);
	return (indices);
}

int	*get_lis(int	*arr, int n)
{
	int	*lis;
	int	*prev;
	int	*indices;

	lis = (int *)malloc(n * sizeof(int));
	prev = (int *)malloc(n * sizeof(int));
	int	i;
	i = 0;
	while (i < n)
	{
		lis[i] = 1;
		prev[i] = -1;
		i++;
	}
	build_lis_prev(arr, lis, prev, n);
	indices = get_indices(arr, lis, prev, n);
	free(lis);
	free(prev);
	return (indices);
}
