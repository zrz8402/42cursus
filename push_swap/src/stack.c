/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:32:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/21 17:35:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_cb *cb, int size)
{
	cb->stack = malloc(size * sizeof(int));
	if (!cb->stack)
		cb->stack = NULL;
	cb->size = size;
	cb->head = 0;
	cb->tail = 0;
	cb->count = 0;
}

t_cb	get_stack(char	**av)
{
	char	**strs;
	int		size;
	t_cb	stack_a;
	int		error;
	int		i;

	strs = get_strs(av);
	size = array_size(strs);
	init_stack(&stack_a, size);
	if (!stack_a.stack)
		return (free_arr(strs), ft_error(), stack_a);
	i = 0;
	while (strs[i])
	{
		error = SUCCESS;
		stack_a.stack[i] = stoi(strs[i], &error);
		if (error != SUCCESS)
			return (free_arr(strs), free(stack_a.stack), ft_error(), stack_a);
		stack_a.tail++;
		stack_a.count++;
		i++;
	}
	free_arr(strs);
	stack_a.stack = transform(stack_a.stack, stack_a.size);
	return (stack_a);
}

int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sorted(int *arr, int n)
{
	int	i;

	if (n == 0 || n == 1)
		return (1);
	i = 1;
	while (i < n)
	{
		if (arr[i - 1] > arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	*transform(int *arr, int n)
{
	int	i;
	int	j;
	int	rank;
	int	*nums;

	i = 0;
	nums = malloc(n * sizeof(int));
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
	return (nums);
}