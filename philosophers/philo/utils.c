/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:03:59 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/02 18:06:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
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
	if (ft_atoi(av[1]) > MAX_PHILO || ft_atoi(av[1]) < 1
		|| check_arg(av[1]) < 0)
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

// sleep() only allows for sleeping for whole seconds
// Fine-Grained Control:
// 	usleep in small increments gives the program more control over the timing
// 	without consuming too much CPU
// 	as it does not need to constantly poll the time without any sleep.
void	ft_usleep(long int time_in_microseconds)
{
	long int	start;

	start = get_current_time() * 1000;
	while ((get_current_time() * 1000 - start) < time_in_microseconds)
		usleep(100);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
