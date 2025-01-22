/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:07:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/22 12:40:28 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	write_message("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	write_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	write_message("has taken a fork", philo);
	if (philo->num_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	write_message("has taken a fork", philo);
	write_message("is eating", philo);
	philo->last_meal = get_current_time();
	ft_usleep(philo->time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	finish(t_philo *philo)
{
	pthread_mutex_lock(philo->finish_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->finish_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->finish_lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!finish(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (arg);
}
