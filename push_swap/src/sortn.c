/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:30:37 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/31 19:35:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_b(t_data *data)
{
	int	i;
	int	j;
	int	*indices;
	int	len;

	indices = get_lis(data, &len);
	i = 0;
	j = 0;
	while (i < data->a.size)
	{
		if (j < len && i == indices[j])
		{
			ra(data);
			j++;
		}
		else
			pb(data);
		i++;
	}
	free(indices);
}

void	ft_move_to_a(t_data *data)
{
	t_move	*moves;
	int		i;

	moves = malloc(data->b.count * sizeof(t_move));
	if (!moves)
		ft_error(data);
	i = 0;
	while (i < data->b.count)
	{
		if (i <= data->b.count / 2)
			moves[i].pos_b = i;
		else
			moves[i].pos_b = i - data->b.count;
		moves[i].pos_a = get_pos_a(data->b.stack[i], data->a);
		moves[i].min = calculate_move(moves[i].pos_a, moves[i].pos_b);
		i++;
	}
	i = min_move_index(moves, data->b.count);
	move(data, moves, i);
	free(moves);
}

void	sortn(t_data *data)
{
	int	i;

	if (is_sorted(data->a.stack, data->a.size))
		return ;
	ft_move_to_b(data);
	while (data->b.count > 0)
		ft_move_to_a(data);
	i = 0;
	while (data->a.stack[i] != 1)
		i++;
	if (i < data->a.size / 2)
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
