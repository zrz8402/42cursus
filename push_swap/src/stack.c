/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:32:23 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/26 20:01:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cb	get_stack_a(char **av)
{
	char	**strs;
	int		size;
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
	a.start = 0;
	a.count = a.size;
	return (a);
}

void	init_data(t_cb a, t_data *data)
{
	data->a = a;
	data->b.stack = malloc(a.size * sizeof(int));
	if (!data->b.stack)
		return (free(data->a.stack), ft_error());
	ft_memset(data->b.stack, 0, (a.size * sizeof(int)));
	data->b.size = a.size;
	data->b.start = 0;
	data->b.count = 0;
	data->ops = NULL;
}

int	is_sorted(int *arr, int n)
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
