/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:42:59 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 18:40:28 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rarb(t_data *data, int pos_a, int pos_b)
{
	while (pos_a && pos_b)
	{
		rr(data);
		pos_a--;
		pos_b--;
	}
	while (pos_a)
	{
		ra(data);
		pos_a--;
	}
	while (pos_b)
	{
		rb(data);
		pos_b--;
	}
	pa(data);
}

void	move_rrarrb(t_data *data, int pos_a, int pos_b)
{
	while (pos_a && pos_b)
	{
		rrr(data);
		pos_a++;
		pos_b++;
	}
	while (pos_a)
	{
		rra(data);
		pos_a++;
	}
	while (pos_b)
	{
		rrb(data);
		pos_b++;
	}
	pa(data);
}

void	move_rarrb(t_data *data, int pos_a, int pos_b)
{
	while (pos_a)
	{
		ra(data);
		pos_a--;
	}
	while (pos_b)
	{
		rrb(data);
		pos_b++;
	}
	pa(data);
}

void	move_rrarb(t_data *data, int pos_a, int pos_b)
{
	while (pos_a)
	{
		rra(data);
		pos_a++;
	}
	while (pos_b)
	{
		rb(data);
		pos_b--;
	}
	pa(data);
}

void	move(t_data *data, t_move *moves, int i)
{
	if (moves[i].pos_a >= 0 && moves[i].pos_b >= 0)
		move_rarb(data, moves[i].pos_a, moves[i].pos_b);
	else if (moves[i].pos_a < 0 && moves[i].pos_b < 0)
		move_rrarrb(data, moves[i].pos_a, moves[i].pos_b);
	else if (moves[i].pos_a >= 0 && moves[i].pos_b < 0)
		move_rarrb(data, moves[i].pos_a, moves[i].pos_b);
	else
		move_rrarb(data, moves[i].pos_a, moves[i].pos_b);
}
