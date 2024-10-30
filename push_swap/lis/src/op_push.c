/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:29:16 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 11:47:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_cb *from, t_cb *to)
{
	int	i;

	i = to->count;
	while (i > 0)
	{
		to->stack[i] = to->stack[i - 1];
		i--;
	}
	to->stack[0] = from->stack[0];
	to->count++;
	from->count--;
	i = 0;
	while (i < from->count)
	{
		from->stack[i] = from->stack[i + 1];
		i++;
	}
	from->stack[i] = 0;
}

void	pa(t_data *data)
{
	push(&data->b, &data->a);
	printf("%s\n", "pa");
}

void	pb(t_data *data)
{
	push(&data->a, &data->b);
	printf("%s\n", "pb");
}
