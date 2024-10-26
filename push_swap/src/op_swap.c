/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:46:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/26 20:05:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_cb *cb)
{
	int	tmp;
	int	*first;
	int	*second;

	first = &cb->stack[cb->start];
	second = &cb->stack[(cb->start + 1) % cb->size];
	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	sa(t_data *data)
{
	op_swap(&data->a);
	add_op(data->ops, SA);
	printf("%s\n", "SA");
}

void	sb(t_data *data)
{
	op_swap(&data->b);
	add_op(data->ops, SB);
	printf("%s\n", "SB");
}
