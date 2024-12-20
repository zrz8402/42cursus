/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:46:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/31 11:31:09 by ruzhang          ###   ########.fr       */
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

void	sa(t_data *data)
{
	if (data->a.count < 2)
		return ;
	swap(&data->a.stack[0], &data->a.stack[1]);
	if (data->write)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data)
{
	if (data->b.count < 2)
		return ;
	swap(&data->b.stack[0], &data->b.stack[1]);
	if (data->write)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
{
	if (data->a.count < 2 || data->b.count < 2)
		return ;
	swap(&data->a.stack[0], &data->a.stack[1]);
	swap(&data->b.stack[0], &data->b.stack[1]);
	if (data->write)
		ft_putstr_fd("ss\n", 1);
}
