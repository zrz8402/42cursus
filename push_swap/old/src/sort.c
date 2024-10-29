/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:26:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/24 14:13:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a.stack[(data->a.head) % data->a.size];
	second = data->a.stack[(data->a.head + 1) % data->a.size];
	third = data->a.stack[(data->a.head + 2) % data->a.size];
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
		if (data->a.stack[data->a.head] == 1
			|| data->a.stack[data->a.head] == 2)
		{
			pb(data);
			count++;
		}
		else
			ra(data);
	}
	sort_three(data);
	if (data->b.stack[data->b.head]
		< data->b.stack[(data->b.head + 1) % data->b.size])
		sb(data);
	pa(data);
	if (data->b.stack[0] < data->b.stack[1])
		sb(data);
	pa(data);
}

void	sort(t_data *data)
{
	
}
