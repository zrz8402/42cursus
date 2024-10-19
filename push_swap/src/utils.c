/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:02:01 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/19 20:22:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_cb *cb, int size)
{
	cb->stack = malloc(size * sizeof(int));
	if (!cb->stack)
		ft_error("Error\n");
	cb->size = size;
	cb->head = 0;
	cb->tail = 0;
	cb->count = 0;
}

void	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(0);
}