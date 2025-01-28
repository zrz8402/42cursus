/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:22:23 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/28 13:58:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	write_message(char *message, t_philo *philo)
{
	size_t	time;

	sem_wait(philo->write_sem);
	time = get_current_time() - philo->start_time;
	if (!finish(philo))
		printf("%zu %d %s\n", time, philo->id, message);
	sem_post(philo->write_sem);
}

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

int	philo_is_dead(t_philo *philo)
{
	if (get_current_time() - philo->last_meal >= philo->time_to_die)
	{
		write_message("died", philo);
		return (1);
	}
	return (0);
}

void	routine(t_philo *philo)
{
	pthread_t	death_thread;

	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		if (philo_is_dead(philo))
			exit(1);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}
