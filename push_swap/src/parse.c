/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:20:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/20 18:46:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_str(char *s1, char *s2)
{
	char	*str;
	char	*tmp;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + 1 + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	tmp = str;
	if (s1)
	{
		i = 0;
		while (s1[i])
			*tmp++ = s1[i++];
		free(s1);
		*tmp++ = ' ';
	}
	if (s2)
	{
		while (*s2)
			*tmp++ = *s2++;
	}
	*tmp = '\0';
	return (str);
}

char	**get_strs(char **av)
{
	char	*tmp;
	char	**strs;
	int		size;

	tmp = NULL;
	while (*av)
	{
		if (ft_isempty(*av))
			return (free(tmp), ft_error(), NULL);
		tmp = join_str(tmp, *av);
		av++;
	}
	strs = ft_split(tmp, ' ');
	free(tmp);
	return (strs);
}

void	init_stack(t_cb *cb, int size)
{
	cb->stack = malloc(size * sizeof(int));
	if (!cb->stack)
		cb->stack = NULL;
	cb->size = size;
	cb->head = 0;
	cb->tail = 0;
	cb->count = 0;
}

int	stoi(char *s, int *error)
{
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		result = result * 10 + sign * (*s - '0');
		if (result > INT_MAX || result < INT_MIN)
		{
			*error = OUT_OF_BOUNDS;
			return (0);
		}
		s++;
	}
	if (*s)
		*error = NOT_INT;
	return ((int)result);
}

t_cb	get_stack(char	**av)
{
	char	**strs;
	int		size;
	t_cb	stack_a;
	int		error;
	int		i;

	strs = get_strs(av);
	size = array_size(strs);
	init_stack(&stack_a, size);
	if (!stack_a.stack)
		return (free_arr(strs), ft_error(), stack_a);
	i = 0;
	while (strs[i])
	{
		error = SUCCESS;
		stack_a.stack[i] = stoi(strs[i], &error);
		if (error != SUCCESS)
			return (free_arr(strs), free(stack_a.stack), ft_error(), stack_a);
		stack_a.tail++;
		stack_a.count++;
		i++;
	}
	free_arr(strs);
	return (stack_a);
}
