/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:29:16 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/23 19:18:08 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_cb *from, t_cb *to)
{
	if (!is_empty(to))
		to->tail++;
	to->stack[to->tail] = to->stack[to->head];
	to->stack[to->head] = from->stack[from->head];
	from->stack[from->head] = 0;
	from->head = (from->head + 1) % from->size;
}

void	pa(t_data *data)
{
	push(&data->b, &data->a);
	add_op(data->ops, PA);
}

void	pb(t_data *data)
{
	push(&data->a, &data->b);
	add_op(data->ops, PB);
}
