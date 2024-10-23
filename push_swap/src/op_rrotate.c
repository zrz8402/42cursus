/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:54 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/23 15:54:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_cb *cb)
{
	cb->head = (cb->head - 1 + cb->size) % cb->size;
	if (!is_full(cb))
		swap(&cb->stack[cb->head], &cb->stack[cb->tail]);
	cb->tail = (cb->tail - 1 + cb->size) % cb->size;
}

void	rra(t_data *data)
{
	r_rotate(&data->a);
	add_op(data->ops, RRA);
}

void	rrb(t_data *data)
{
	r_rotate(&data->b);
	add_op(data->ops, RRB);
}