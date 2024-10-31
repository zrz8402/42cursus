/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:32:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/31 10:53:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_size(char **arr)
{
	int	size;

	size = 0;
	while (*(arr++))
		size++;
	return (size);
}

int	*transform(int *arr, int n)
{
	int	i;
	int	j;
	int	rank;
	int	*nums;

	i = 0;
	nums = malloc(n * sizeof(int));
	if (!nums)
		return (free(arr), ft_error(), nums);
	while (i < n)
	{
		j = 0;
		rank = 0;
		while (j < n)
		{
			if (arr[i] >= arr[j])
				rank++;
			j++;
		}
		nums[i] = rank;
		i++;
	}
	free(arr);
	return (nums);
}

t_cb	get_stack_a(char **av)
{
	char	**strs;
	t_cb	a;
	int		i;

	strs = get_strs(av);
	a.size = array_size(strs);
	a.stack = malloc(a.size * sizeof(int));
	if (!a.stack)
		return (free_arr(strs), ft_error(), a);
	i = 0;
	while (strs[i])
	{
		if (!is_valid(strs[i]))
			return (free_arr(strs), free(a.stack), ft_error(), a);
		a.stack[i] = ft_atoi(strs[i]);
		i++;
	}
	free_arr(strs);
	if (check_duplicates(a.stack, a.size))
		return (free(a.stack), ft_error(), a);
	a.count = a.size;
	return (a);
}

void	init_data(t_cb a, t_data *data)
{
	a.stack = transform(a.stack, a.size);
	data->a = a;
	data->b.stack = malloc(a.size * sizeof(int));
	if (!data->b.stack)
		return (free(data->a.stack), ft_error());
	ft_memset(data->b.stack, 0, (a.size * sizeof(int)));
	data->b.size = a.size;
	data->b.count = 0;
	data->write = 1;
}
