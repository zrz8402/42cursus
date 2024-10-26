/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:27 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/26 20:16:05 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_cb *cb)
{
	if (cb->size != cb->count)
		swap(&cb->stack[cb->start], &cb->stack[(cb->start + cb->count) % cb->size]);
	cb->start = (cb->start + 1) % cb->size;
}

void	ra(t_data *data)
{
	rotate(&data->a);
	add_op(data->ops, RA);
	printf("%s\n", "RA");
}

void	rb(t_data *data)
{
	rotate(&data->b);
	add_op(data->ops, RB);
	printf("%s\n", "RB");
}
