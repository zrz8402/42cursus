/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:54 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 12:21:42 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_cb *cb)
{
	int	tmp;
	int	i;

	tmp = cb->stack[cb->count - 1];
	i = cb->count - 1;
	while (i > 0)
	{
		cb->stack[i] = cb->stack[i - 1];
		i--;
	}
	cb->stack[0] = tmp;
}

void	rra(t_data *data)
{
	r_rotate(&data->a);
	printf("%s\n", "rra");
}

void	rrb(t_data *data)
{
	r_rotate(&data->b);
	printf("%s\n", "rrb");
}

void	rrr(t_data *data)
{
	r_rotate(&data->a);
	r_rotate(&data->b);
	printf("%s\n", "rrr");
}
