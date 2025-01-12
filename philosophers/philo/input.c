/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:53:14 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/12 16:05:48 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	check_arg(char *arg)
{
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (-1);
		arg++;
	}
	return (0);
}

int	check_input(char **av)
{
	if (ft_atoi(av[1]) > MAX_PHILO || ft_atoi(av[1]) < 1 || check_arg(av[1]) < 0)
		return (-1);
	if (ft_atoi(av[2]) < 1 || check_arg(av[2]) < 0)
		return (-1);
	if (ft_atoi(av[3]) < 1 || check_arg(av[3]) < 0)
		return (-1);
	if (ft_atoi(av[4]) < 1 || check_arg(av[4]) < 0)
		return (-1);
	if (av[5] && (ft_atoi(av[5]) < 1 || check_arg(av[5]) < 0))
		return (-1);
	return (0);
}