/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:21:55 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/22 10:29:17 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// examples:
// (time) (philo_id) (message)
// (time 0) (philo_1) (has teken a fork)
// (time 0) (philo_1) (is eating)
void	write_message(char *message, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!philo_is_dead(philo))
		printf("%zu %d %s\n", time, philo->id, message);
	pthread_mutex_unlock(philo->write_lock);
}

int	philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->finish_lock);
	if (get_current_time() - philo->last_meal >= philo->time_to_die)
	{
		return (1);
	}
	pthread_mutex_unlock(philo->finish_lock);
	return (0);
}

int	has_dead(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].num_philos)
	{
		if(philo_is_dead(&philos[i]))
		{
			write_message("died", &philos[i]);
			pthread_mutex_lock(philos[0].finish_lock);
			*philos->dead = 1;
			pthread_mutex_lock(philos[0].finish_lock);
		}
	}
	return (0);
}

int	all_ate(t_philo *philos)
{
	int	i;

	i = -1;
	if (philos[0].num_times_must_eat == -1)
		return (0);
	while (++i < philos[0].num_philos)
	{
		if (philos[i].meals_eaten < philos[i].num_times_must_eat)
			return (0);
	}
	printf("id %d eats %d meals\n", philos[0].id, philos[0].meals_eaten);
	printf("id %d eats %d meals\n", philos[1].id, philos[1].meals_eaten);
	printf("id %d eats %d meals\n", philos[2].id, philos[2].meals_eaten);
	pthread_mutex_lock(philos[0].finish_lock);
	*philos->dead = 1;
	pthread_mutex_unlock(philos[0].finish_lock);
	return (1);
}

void	*monitor(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (has_dead(philos) == 1 || all_ate(philos) == 1)
			break ;
	}
	return (arg);
}
