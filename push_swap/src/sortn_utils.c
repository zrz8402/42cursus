/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortn_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:03 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 17:36:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	min_i;

	i = 1;
	if ((n < cb.stack[0] && n > cb.stack[cb.count - 1]))
		return (0);
	else if (n < ft_min(cb, &min_i) || n > ft_max(cb))
		i = min_i;
	else
	{
		while (!(n > cb.stack[i - 1] && n < cb.stack[i]))
			i++;
	}
	if (i > cb.count / 2)
		i -= cb.count;
	return (i);
}

int	calculate_move(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		return (a + b);
	}
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
