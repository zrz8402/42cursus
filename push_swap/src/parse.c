/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:20:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/19 22:09:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stoi(char *s, t_error error)
{
	int	result;
	int	sign;
	int	tmp;

	result = 0;
	sign = 1;
	while(isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while(*s)
	{
		if(!ft_isdigit(*s))
		{
			error = NOT_INT;
			break ;
		}
		tmp = *s - '0';
		if ((sign > 0 && result > (INT_MAX - tmp))
			|| sign < 0 && -result < (INT_MIN + tmp))
		{
			error = OUT_OF_BOUND;
			break ;
		}
		result = result * 10 + tmp;
	}
	return (result * sign);	
}

void	fill_stack(t_cb *cb, int ac, char **av)
{
	while(++av)
	{
		cb->stack[cb->count++] = ft_stoi(*av);
	}
}