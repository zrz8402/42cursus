/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:54 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/24 12:47:47 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_cb *cb)
{
	if (!is_full(cb))
		swap(&cb->stack[(cb->head - 1 + cb->size) % cb->size],
			&cb->stack[cb->tail]);
	cb->head = (cb->head - 1 + cb->size) % cb->size;
	cb->tail = (cb->tail - 1 + cb->size) % cb->size;
}

void	rra(t_data *data)
{
	r_rotate(&data->a);
	add_op(data->ops, RRA);
	printf("%s\n", "RRA");
}

void	rrb(t_data *data)
{
	r_rotate(&data->b);
	add_op(data->ops, RRB);
	printf("%s\n", "RRB");
}
