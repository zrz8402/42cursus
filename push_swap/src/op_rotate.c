/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:03:27 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 15:28:55 by ruzhang          ###   ########.fr       */
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
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data)
{
	rotate(&data->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	ft_putstr_fd("rr\n", 1);
}
