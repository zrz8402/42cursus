/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:20:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/21 17:39:22 by ruzhang          ###   ########.fr       */
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

int	validate    (char *s, int *error)
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
