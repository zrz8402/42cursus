/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:20:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/30 15:39:40 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isempty(char *s)
{
	while (*s)
	{
		if (!(*s == 32 || (*s >= 9 && *s <= 13)))
			return (0);
		s++;
	}
	return (1);
}

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

int	is_valid(char *s)
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
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		result = result * 10 + sign * (*s - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (0);
		s++;
	}
	return (1);
}

int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
