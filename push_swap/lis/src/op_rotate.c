/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:27 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 12:21:35 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_cb *cb)
{
	int	tmp;
	int	i;

	tmp = cb->stack[0];
	i = 1;
	while (i < cb->count)
	{
		cb->stack[i - 1] = cb->stack[i];
		i++;
	}
	cb->stack[cb->count - 1] = tmp;
}

void	ra(t_data *data)
{
	rotate(&data->a);
	printf("%s\n", "ra");
}

void	rb(t_data *data)
{
	rotate(&data->b);
	printf("%s\n", "rb");
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	printf("%s\n", "rr");
}
