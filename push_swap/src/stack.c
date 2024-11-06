/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:32:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/06 14:57:02 by ruzhang          ###   ########.fr       */
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

int	*transform(t_data *data, int *arr)
{
	int	i;
	int	j;
	int	rank;
	int	*nums;

	i = 0;
	nums = malloc(data->a.size * sizeof(int));
	if (!nums)
		ft_error(data);
	while (i < data->a.size)
	{
		j = 0;
		rank = 0;
		while (j < data->a.size)
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

void	get_stack_a(char **av, t_data *data)
{
	char	**strs;
	int		i;

	strs = get_strs(av, data);
	data->a.size = array_size(strs);
	data->a.stack = malloc(data->a.size * sizeof(int));
	if (!data->a.stack)
		f_error(data, strs);
	i = 0;
	while (strs[i])
	{
		if (!is_valid(strs[i]))
			f_error(data, strs);
		data->a.stack[i] = ft_atoi(strs[i]);
		i++;
	}
	free_arr(strs);
	if (check_duplicates(data->a.stack, data->a.size))
		ft_error(data);
	data->a.count = data->a.size;
}

void	init_data(char **av, t_data *data)
{
	data->a.stack = NULL;
	data->b.stack = NULL;
	get_stack_a(++av, data);
	data->a.stack = transform(data, data->a.stack);
	data->b.stack = malloc(data->a.size * sizeof(int));
	if (!data->b.stack)
		ft_error(data);
	ft_memset(data->b.stack, 0, (data->a.size * sizeof(int)));
	data->b.size = data->a.size;
	data->b.count = 0;
	data->write = 1;
}
