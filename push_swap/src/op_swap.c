/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:46:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/21 18:21:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_cb *cb)
{
	int	tmp;

	tmp = cb->stack[0];
	cb->stack[0] = cb->stack[1];
	cb->stack[1] = tmp;
}

void	sa(t_data *data)
{
	swap(&data->a);
	add_op(data->ops, sa);
}

void	sb(t_data *data)
{
	swap(&data->b);
	add_op(data->ops, sb);
}
