/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:44:41 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/22 12:41:22 by ruzhang          ###   ########.fr       */
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

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// sleep() only allows for sleeping for whole seconds
// Fine-Grained Control:
// 	usleep in small increments gives the program more control over the timing
// 	without consuming too much CPU
// 	as it does not need to constantly poll the time without any sleep.
void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
}
