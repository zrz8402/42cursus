/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:34:24 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/03 11:48:48 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_status(philo, "has taken a fork");
	ft_usleep(philo->table->time_to_die * 2 * 1000);
	pthread_mutex_unlock(philo->first_fork);
}

void	ft_eat(t_philo *philo)
{
	if (philo->table->num_philos == 1)
	{
		one_philo(philo);
		return ;
	}
	if (philo->first_fork < philo->second_fork)
	{
		pthread_mutex_lock(philo->first_fork);
		pthread_mutex_lock(philo->second_fork);
	}
	else
	{
		pthread_mutex_lock(philo->second_fork);
		pthread_mutex_lock(philo->first_fork);
	}
	print_status(philo, "has taken a fork");
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->table->meal_mutex);
	print_status(philo, "is eating");
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 10);
	while (!finished(philo, 1))
	{
		if (finish_eating(philo))
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	return (0);
}
