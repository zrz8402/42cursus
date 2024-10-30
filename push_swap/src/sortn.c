/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:30:37 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 14:55:20 by ruzhang          ###   ########.fr       */
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
		if (i == indices[j])
		{
			ra(data);
			j++;
		}
		else
			pb(data);
	}
	// printf("\n---------a------------\n");
	// for (int i = 0; i < data->a.size; i++)
	// 	printf("%d ", data->a.stack[i]);
	// printf("\n---------b------------\n");
	// for (int i = 0; i < data->b.size; i++)
	// {
	// 	printf("%d ", data->b.stack[i]);
	// }
	// printf("\n\n");

	while (data->b.count > 0)
		count_move(data);
		
	// printf("\n---------a------------\n");
	// for (int i = 0; i < data->a.size; i++)
	// 	printf("%d ", data->a.stack[i]);
	// printf("\n---------b------------\n");
	// for (int i = 0; i < data->b.size; i++)
	// {
	// 	printf("%d ", data->b.stack[i]);
	// }
	// printf("\n\n");
	int k = 0;
	while (data->a.stack[k] != 1)
		k++;
	if (k < data->a.size / 2)
	{
		while (data->a.stack[0] != 1)
			ra(data);
	}
	else
	{
		while (data->a.stack[0] != 1)
			rra(data);
	}
}

int	ft_max(t_cb cb)
{
	int	max;

	max = cb.stack[0];
	while (cb.count--)
	{
		if (max < cb.stack[cb.count])
			max = cb.stack[cb.count];
	}
	return (max);
}

int	ft_min(t_cb cb, int *min_n_index)
{
	int	min;

	*min_n_index = 0;
	min = cb.stack[0];
	while (cb.count--)
	{
		if (min > cb.stack[cb.count])
		{
			min = cb.stack[cb.count];
			*min_n_index = cb.count;
		}
	}
	return (min);
}

int	get_pos_a(int n, t_cb cb)
{
	int	i;

	i = 1;
	int min_i;

	//printf("(n%d fan:%d lan:%d ", n, cb.stack[0], cb.stack[cb.count - 1]);
	if ((n < cb.stack[0] && n > cb.stack[cb.count - 1]))
		return (0);
	else if (n < ft_min(cb, &min_i) || n > ft_max(cb))
		i = min_i;
	else {
		while (!(n > cb.stack[i - 1] && n < cb.stack[i]))
			i++;
	}
	//printf("min:%d min_i:%d max:%d max_i:%d i:%d)\n", ft_min(cb, &min_i), min_i, ft_max(cb, &max_i), max_i, i);
	if (i > cb.count / 2)
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
			index = i;
		}
		i++;
	}
	return (index);
}

void	count_move(t_data *data)
{
	t_move	*moves;

	moves = malloc(data->b.count * sizeof(t_move));
	for (int i = 0; i < data->b.count; i++)
	{
		if (i <= data->b.count / 2)
			moves[i].pos_b = i;
		else
			moves[i].pos_b = i - data->b.count;
		moves[i].pos_a = get_pos_a(data->b.stack[i], data->a);
		//printf("(%d %d ", moves[i].pos_a, moves[i].pos_b);
		if (moves[i].pos_a > 0 && moves[i].pos_b > 0)
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
		else if (moves[i].pos_a >= 0 && moves[i].pos_b <= 0)
		{
				moves[i].min = moves[i].pos_a - moves[i].pos_b;
				moves[i].pos_b = -moves[i].pos_b;
				//printf("min %d ", moves[i].min);
				moves[i].type = RARRB;
		}
		else
		{
				moves[i].min = moves[i].pos_b - moves[i].pos_a;
				moves[i].pos_a = -moves[i].pos_a;
				moves[i].type = RRARB;
			
		}
		//printf("%d)\n", moves[i].min);
	}
	// printf("\n");
	int i = min_move_index(moves, data->b.count);
	//printf("%d\n", i);
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