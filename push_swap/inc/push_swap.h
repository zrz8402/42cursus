/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:21:22 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/19 20:22:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_cb
{
	int	*stack;
	int	size;
	int	head;
	int	tail;
	int	count;
} t_cb;

void	init_stack(t_cb *cb, int size);

#endif