/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:46:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 12:19:48 by ruzhang          ###   ########.fr       */
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
	swap(&data->a.stack[0], &data->a.stack[1]);
	printf("%s\n", "sa");
}

void	sb(t_data *data)
{
	swap(&data->b.stack[0], &data->b.stack[1]);
	printf("%s\n", "sb");
}

void	ss(t_data *data)
{
	swap(&data->a.stack[0], &data->a.stack[1]);
	swap(&data->b.stack[0], &data->b.stack[1]);
	printf("%s\n", "ss");
}
