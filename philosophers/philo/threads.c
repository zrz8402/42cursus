/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:08:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/22 10:25:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		finish(t_philo *philo)
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

void	cleanup(char *message, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (message)
		printf("%s\n", message);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->eat_lock);
	pthread_mutex_destroy(&table->finish_lock);
	while (i < table->philos[i].num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	thread(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	control;
	int			i;

	if (pthread_create(&control, NULL, &monitor, table->philos) != 0)
		return (cleanup("Thread creation error", table, forks));
	i = -1;
	while (++i < table->philos[0].num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine, &table->philos[i]))
			return (cleanup("Thread creation error", table, forks));
	}
	if (pthread_join(control, NULL) != 0)
		return (cleanup("Thread join error", table, forks));
	i = -1;
	while (++i < table->philos[0].num_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (cleanup("Thread join error", table, forks));
	}
}
