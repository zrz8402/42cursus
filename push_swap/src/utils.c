/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:02:01 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/20 18:51:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_isempty(char *s)
{
	while (*s)
	{
		if (!ft_isspace(*s))
			return (0);
		s++;
	}
	return (1);
}

int	array_size(char **arr)
{
	int	size;

	size = 0;
	while (*(arr++))
		size++;
	return (size);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
