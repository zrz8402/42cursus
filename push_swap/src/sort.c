/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:26:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/26 21:01:34 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a.stack[(data->a.start) % data->a.size];
	second = data->a.stack[(data->a.start + 1) % data->a.size];
	third = data->a.stack[(data->a.start + 2) % data->a.size];
	if (first < second && second < third) // 123
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
	else //321 first > second && second > third
	{
		sa(data);
		rra(data);
	}
}

void	sort_five(t_data *data)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if (data->a.stack[data->a.start] == 1
			|| data->a.stack[data->a.start] == 2)
		{
			pb(data);
			count++;
		}
		else
			ra(data);
	}
	sort_three(data);
	if (data->b.stack[data->b.start]
		< data->b.stack[(data->b.start + 1) % data->b.size])
		sb(data);
	pa(data);
	if (data->b.stack[0] < data->b.stack[1])
		sb(data);
	pa(data);
}

void	turk_sort(t_data *data)
{
	pb(data);
	pb(data);
	
	int	pos_a;
	int	pos_b;
	int	*move;
	move = malloc(data->a.count * sizeof(int));
	for (int i = 0; i < data->a.count; i++)
	{
		if (i <= data->a.count / 2)
			pos_a = i;
		else
			pos_a = data->a.count - i;
		printf("(%d)", pos_a);
	}
}

// int	rank(int n, int *arr, int size)
// {
// 	int rank;

// 	rank = 0;
// 	// for (int i = 0; i < size; i++)
// 	// {
// 	// 	if (n > arr[i])
// 	// }
// }
