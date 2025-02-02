/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:19:54 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/02 18:07:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	cleanup(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philos)
		pthread_mutex_destroy(table->forks[i]);
	i = -1;
	while (++i < table->num_philos)
	{
		free(table->philos[i]);
		free(table->forks[i]);
	}
	pthread_mutex_destroy(&table->eating_mutex);
	pthread_mutex_destroy(&table->log_mutex);
	pthread_mutex_destroy(&table->monitor_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	free(table->forks);
	free(table->philos);
}

int	simulation(t_table *table)
{
	int	i;

	table->start_time = get_current_time();
	if (pthread_create(&table->monitor, NULL, monitor, table) != 0)
		return (0);
	i = -1;
	while (++i < table->num_philos)
	{
		table->philos[i]->last_meal_time = table->start_time;
		if (pthread_create(&table->philos[i]->thread, NULL,
				routine, table->philos[i]) != 0)
			return (0);
	}
	i = -1;
	while (++i < table->num_philos)
		pthread_join(table->philos[i]->thread, NULL);
	pthread_join(table->monitor, NULL);
	return (1);
}
