/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:30:37 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/29 13:40:12 by ruzhang          ###   ########.fr       */
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
	while (data->b.count > 0)
{		count_move(data);
	printf("\n---------a------------\n");
	for (int i = 0; i < data->a.size; i++)
	{
		int n = (data->a.start + i) % data->a.size;
		printf("%d ", data->a.stack[n]);
	}
	printf("\n----------b-----------\n");
	for (int i = 0; i < data->b.size; i++)
	{
		int n = (data->b.start + i) % data->b.size;
		printf("%d ", data->b.stack[n]);
	}
	printf("\n---------------------\n");
	}
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
	if (n < cb.stack[cb.start] && n > cb.stack[(cb.start + cb.count - 1) % cb.size])
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
	if (i > cb.count)
		i = -1;
	else if (i > cb.count / 2)
		i -= cb.count;
	return (i);
}

int	min_move_index(t_move *moves, int size)
{
	int	i;
	int	n;
	int	index;

	i = 0;
	n = moves[i].min;
	index = 0;
	while (i < size)
	{
		if (n > moves[i].min)
		{
			n = moves[i].min;
			index++;
		}
		i++;
	}
	return (index);
}

void	count_move(t_data *data)
{
	int	pos_a;
	int	pos_b;
	t_move	*moves;

	moves = malloc(data->b.count * sizeof(t_move));
	for (int i = 0; i < data->b.count; i++)
	{
		if (i <= data->b.count / 2)
			moves[i].pos_b = i;
		else
			moves[i].pos_b = i - data->b.count;
		moves[i].pos_a = get_pos_a(data->b.stack[(data->b.start + i)
				% data->b.size], data->a);
		//printf("(%d %d)\n", moves[i].pos_a, moves[i].pos_b);
		if (moves[i].pos_a >= 0 && moves[i].pos_b >= 0)
		{
			if (moves[i].pos_a > moves[i].pos_b)
				moves[i].min = moves[i].pos_a;
			else
				moves[i].min = moves[i].pos_b;
			moves[i].type = RARB;
		}
		else if (moves[i].pos_a < 0 && moves[i].pos_b < 0)
		{
			if (moves[i].pos_a > moves[i].pos_b)
				moves[i].min = -moves[i].pos_b;
			else
				moves[i].min = -moves[i].pos_a;
			moves[i].pos_a = -moves[i].pos_a;
			moves[i].pos_b = -moves[i].pos_b;
			moves[i].type = RRARRB;
		}
		else if (pos_a > 0 && moves[i].pos_b < 0)
		{
			if (moves[i].pos_a - moves[i].pos_b < moves[i].pos_b + data->b.count)
			{
				moves[i].min = moves[i].pos_a - moves[i].pos_b;
				moves[i].pos_b = -moves[i].pos_b;
				moves[i].type = RARRB;
			}
			else
			{
				moves[i].pos_b = moves[i].pos_b + data->b.count;
				moves[i].min = moves[i].pos_b;
				moves[i].type = RARB;	
			}
		}
		else
		{
			if (moves[i].pos_b - moves[i].pos_a < moves[i].pos_a + data->a.count)
			{
				moves[i].min = moves[i].pos_b - moves[i].pos_a;
				moves[i].pos_a = -moves[i].pos_a;
				moves[i].type = RRARB;
			}
			else
			{
				moves[i].pos_a = moves[i].pos_a + data->a.count;
				moves[i].min = moves[i].pos_a;
				moves[i].type = RARB;	
			}
		}
		// printf("%d ", moves[i].min);
		// printf("\n");
	}
	int i = min_move_index(moves, data->b.count);
	//printf("%d", i);
	move(i, moves, data);
}


void	move(int i, t_move *moves, t_data *data)
{
	int	m;

	m = 0;
	//printf("(%d %d)\n", moves[i].pos_a, moves[i].pos_b);
	if (moves[i].type == RARB)
	{
		while (m < moves[i].pos_a && m < moves[i].pos_b)
		{
			rr(data);
			m++;
		}
		while (m < moves[i].pos_a || m < moves[i].pos_b)
		{
			if (m < moves[i].pos_a)
				ra(data);
			if (m < moves[i].pos_b)
				rb(data);
			m++;
		}
		pa(data);
	}
	else if (moves[i].type == RRARRB)
	{
		while (m < moves[i].pos_a && m < moves[i].pos_b)
		{
			rrr(data);
			m++;
		}
		while (m < moves[i].pos_a || m < moves[i].pos_b)
		{
			if (m < moves[i].pos_a)
				rra(data);
			if (m < moves[i].pos_b)
				rrb(data);
			m++;
		}
		pa(data);
	}
	else if (moves[i].type == RRARB)
	{
		while (m < moves[i].pos_a && m < moves[i].pos_b)
		{
			rra(data);
			rb(data);
			m++;
		}
		while (m < moves[i].pos_a || m < moves[i].pos_b)
		{
			if (m < moves[i].pos_a)
				rra(data);
			if (m < moves[i].pos_b)
				rb(data);
			m++;
		}
		pa(data);
	}
	else //if (moves[i].type == RARRB)
	{
		while (m < moves[i].pos_a && m < moves[i].pos_b)
		{
			ra(data);
			rrb(data);
			m++;
		}
		while (m < moves[i].pos_a || m < moves[i].pos_b)
		{
			if (m < moves[i].pos_a)
				ra(data);
			if (m < moves[i].pos_b)
				rrb(data);
			m++;
		}
		pa(data);
	}
}