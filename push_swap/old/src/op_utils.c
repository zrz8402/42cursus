/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:52:14 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/24 12:03:17 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	is_full(t_cb *cb)
{
	if ((cb->tail + 1) % cb->size == cb->head)
		return (1);
	return (0);
}

void	add_op(t_list *list, int op)
{
	return ;
}

int	is_empty(t_cb *cb)
{
	if (cb->head == cb->tail && cb->stack[cb->head] == 0)
		return (0);
	return (1);
}
