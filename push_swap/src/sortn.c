/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:30:37 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/27 16:21:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortn(t_data *data)
{
	int	*indices;
	int	j = 0;
	int	last_a;

	indices = get_lis(data->a.stack, data->a.size);
	for (int i = 0; i < data->a.size; i++)
	{
		// last_a = data->a.stack[(data->a.start + data->a.count - 1) % data->a.size];
		// if (data->b.stack[data->b.start] > last_a && data->b.stack[data->b.start] < data->a.stack[indices[j]])
		// {
		// 	pa(data);
		// 	ra(data);
		// }
		if (i == indices[j])
		{
			ra(data);
			j++;
		}
		else
			pb(data);
	}
	count_move(data);
}

int	ft_max(t_cb cb)
{
	int	max;

	max = cb.stack[cb.start];
	while (cb.count--)
	{
		if (max < cb.stack[(cb.start + 1) % cb.size])
			max = cb.stack[(cb.start + 1) % cb.size];
	}
	return (max);
}

int	ft_min(t_cb cb)
{
	int	min;

	min = cb.stack[cb.start];
	while (cb.count--)
	{
		if (min > cb.stack[(cb.start + 1) % cb.size])
			min = cb.stack[(cb.start + 1) % cb.size];
	}
	return (min);
}

int	get_pos_a(int n, t_cb cb)
{
	int	i;

	i = 0;
	if (n < cb.stack[cb.start])
		i = 0;
	else
	{
		while (n > cb.stack[(cb.start + i) % cb.size])
		{
			i++;
			if (i > cb.count)
				break ;
		}
	}
	if (i > cb.count / 2)
		i -= cb.count;
	return (i);
}

void	count_move(t_data *data)
{
	int	pos_a;
	int	pos_b;
	int	*move;

	move = malloc(data->b.count * sizeof(int));
	for (int i = 0; i < data->b.count; i++)
	{
		if (i <= data->b.count / 2)
			pos_b = i;
		else
			pos_b = i - data->b.count;
		pos_a = get_pos_a(data->b.stack[(data->b.start + i) % data->b.size], data->a);
		move[i] = pos_a + pos_b;
		printf("(%d %d)\n", pos_b, pos_a);
	}
}
