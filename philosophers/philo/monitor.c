/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:21:55 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/01 14:27:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_message(char *message, t_philo *philo, t_table *table)
{
	size_t	time;

	pthread_mutex_lock(&table->write_lock);
	time = get_current_time() - philo->start_time;
	printf("%zu %d %s\n", time, philo->id, message);
	pthread_mutex_unlock(&table->write_lock);
}

void	check(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->num_philos)
	{
		philo = &(table->philos[i]);
		pthread_mutex_lock(&philo->time_lock);
		if (get_current_time() - philo->last_meal >= table->time_to_die)
		{
			write_message("died", philo, table);
			pthread_mutex_lock(&table->stop_lock);
			table->stop = 1;
			pthread_mutex_unlock(&table->stop_lock);
			pthread_mutex_unlock(&philo->time_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->time_lock);
	}
}

void	*monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		pthread_mutex_lock(&table->stop_lock);
		if (table->num_finished >= table->num_philos || table->stop)
		{
			pthread_mutex_unlock(&table->stop_lock);
			break ;
		}
		pthread_mutex_unlock(&table->stop_lock);
		check(table);
		ft_usleep(1);
	}
	return (NULL);
}
