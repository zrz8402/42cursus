/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:20:55 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/20 16:06:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stoi(char *s, t_error error)
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
			error = OUT_OF_BOUNDS;
			return (0);
		}
		s++;
	}
	if (*s)
		error = NOT_INT;
	return ((int)result);
}

char	*join_str(char *s1, char *s2)
{
	char	*str;
	char	*tmp;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + 1 + ft_strlen(s2) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	tmp = str;
	if (s1)
	{
		ft_memcpy(tmp, s1, ft_strlen(s1));
		printf("(%s) (%s)\n", s1, tmp);
		free(s1);
		*tmp++ = ' ';
	}
	ft_strlcat(str, s2, len);
	return (str);
}

void	fill_stack(char **av)
{
	char	*tmp;

	tmp = NULL;
	while (*av)
	{
		tmp = join_str(tmp, *av);
		printf("%s\n", tmp);
		av++;
	}
	//printf("%s\n", tmp);
}
