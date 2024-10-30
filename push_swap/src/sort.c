/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:26:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 15:43:18 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a.stack[0];
	second = data->a.stack[1];
	third = data->a.stack[2];
	if (is_sorted(data->a.stack, data->a.count)) // 123
		return ;
	else if (first > second && second < third && first < third) //213
		sa(data);
	else if (first > second && second < third && first > third) //312
		ra(data);
	else if (first < second && second > third && first > third) //231
		rra(data);
	else if (first < second && second > third && first < third) //132
	{
		sa(data);
		ra(data);
	}
	else // 321
	{
		sa(data);
		rra(data);
	}
}

void	sort_five(t_data *data)
{
	int	count;

	count = 0;
	if (is_sorted(data->a.stack, data->a.size))
		return ;
	while (count < 2)
	{
		if (data->a.stack[0] == 1 || data->a.stack[0] == 2)
		{
			pb(data);
			count++;
		}
		else
			ra(data);
	}
	sort_three(data);
	if (data->b.stack[0] < data->b.stack[1])
		sb(data);
	pa(data);
	pa(data);
}
