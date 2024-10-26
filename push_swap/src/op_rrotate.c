/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:54 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/26 20:18:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_cb *cb)
{
	if (cb->size != cb->count)
		swap(&cb->stack[(cb->start - 1 + cb->size) % cb->size],
			&cb->stack[(cb->start + cb->count - 1)  % cb->size]);
	cb->start = (cb->start - 1 + cb->size) % cb->size;
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
