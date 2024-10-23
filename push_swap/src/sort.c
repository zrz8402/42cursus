/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:26:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/23 19:23:00 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a.stack[0];
	second = data->a.stack[1];
	third = data->a.stack[2];
	if (first > second && second < third && first < third) //213
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
	while (count <= 2)
	{
		if (data->a.stack[0] == 1 || data->a.stack[0] == 2)
		{
			pb(data);
			count++;
		}
		else
			ra(data);
		printf("(count%d)", count);
	}
	printf("\n---------a------------\n");
	for (int i = 0; i < data->a.size; i++)
	{
		int n = (data->a.head + i) % data->a.size;
		printf("%d ", data->a.stack[n]);
	}
	printf("\n----------b-----------\n");
	for (int i = 0; i < data->b.size; i++)
	{
		int n = (data->b.head + i) % data->b.size;
		printf("%d ", data->b.stack[n]);
	}
	// sort_three(data);
	// if (data->b.stack[0] < data->b.stack[1])
	// 	sb(data);
	// pa(data);
	// pa(data);
}
