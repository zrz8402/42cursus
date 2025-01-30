/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:22:23 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/30 14:00:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	write_message(char *message, t_philo *philo)
{
	size_t	time;

	sem_wait(philo->write_sem);
	time = get_current_time() - philo->start_time;
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
	if (philo->meals_eaten >= philo->num_times_must_eat)
		sem_post(philo->meal_sem);
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
}

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->death_sem);
		if (get_current_time() - philo->last_meal >= philo->time_to_die)
		{
			write_message("died", philo);
			sem_post(philo->death_sem);
			exit(EXIT_SUCCESS);
		}
		sem_post(philo->death_sem);
	}
	return (arg);
}

void	routine(t_philo *philo, t_table *table)
{
	pthread_t	death_check;
	
	if (pthread_create(&death_check, NULL, &check_death, philo) != 0)
		destroy_all(table, 1, "Thread creation error", EXIT_FAILURE);
	pthread_detach(death_check);
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}
