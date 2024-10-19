/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:21:22 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/19 21:58:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

#include "libft.h"

typedef struct s_cb
{
	int	*stack;
	int	size;
	int	head;
	int	tail;
	int	count;
} t_cb;

typedef enum	e_error
{
	SUCCESS,
	NOT_INT,
	OUT_OF_BOUND,
}	t_error;

void	init_stack(t_cb *cb, int size);
void	ft_error(char *message);
int	isspace(char c);

#endif