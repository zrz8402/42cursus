/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:29:16 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/27 14:11:37 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_cb *from, t_cb *to)
{
	to->start = (to->start - 1 + to->size) % to->size;
	to->stack[to->start] = from->stack[from->start];
	from->stack[from->start] = 0;
	from->start = (from->start + 1) % from->size;
	from->count--;
	to->count++;
}

void	pa(t_data *data)
{
	push(&data->b, &data->a);
	add_op(data->ops, PA);
	//printf("%s\n", "PA");
}

void	pb(t_data *data)
{
	push(&data->a, &data->b);
	add_op(data->ops, PB);
	//printf("%s\n", "PB");
}
