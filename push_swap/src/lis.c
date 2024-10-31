/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:41:09 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/31 19:36:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_lis(int *arr, int *lis, int *prev, int n)
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

int	*get_indices(t_data *data, int *lis, int *prev, int *len)
{
	int	i;
	int	max_index;
	int	*indices;

	*len = 1;
	max_index = 0;
	get_max(lis, data->a.size, len, &max_index);
	indices = (int *)malloc(*len * sizeof(int));
	if (!indices)
	{
		free(lis);
		free(prev);
		ft_error(data);
	}
	i = *len - 1;
	while (max_index != -1)
	{
		indices[i] = max_index;
		max_index = prev[max_index];
		i--;
	}
	free(lis);
	free(prev);
	return (indices);
}

int	*get_lis(t_data *data, int *len)
{
	int	*lis;
	int	*prev;
	int	*indices;
	int	i;

	lis = (int *)malloc(data->a.size * sizeof(int));
	if (!lis)
		ft_error(data);
	prev = (int *)malloc(data->a.size * sizeof(int));
	if (!prev)
	{
		free(lis);
		ft_error(data);
	}
	i = 0;
	while (i < data->a.size)
	{
		lis[i] = 1;
		prev[i] = -1;
		i++;
	}
	build_lis(data->a.stack, lis, prev, data->a.size);
	indices = get_indices(data, lis, prev, len);
	return (indices);
}
