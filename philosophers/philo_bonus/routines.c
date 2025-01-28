/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:22:23 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/28 12:00:52 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_wait(philo->fork_sem);
	write_message("has taken a fork", philo);
	if (philo->num_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		sem_post(philo->fork_sem);
		return ;
	}
	sem_wait(philo->fork_sem);
	write_message("has taken a fork", philo);
	write_message("is eating", philo);
	philo->last_meal = get_current_time();
	ft_usleep(philo->time_to_eat);
	philo->meals_eaten++;
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
}

int	finish(t_philo *philo)
{
	// pthread_mutex_lock(philo->finish_lock);
	if (*philo->dead == 1)
	{
		// pthread_mutex_unlock(philo->finish_lock);
		return (1);
	}
	// pthread_mutex_unlock(philo->finish_lock);
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
