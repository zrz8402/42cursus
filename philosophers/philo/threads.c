/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:08:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/16 14:05:04 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1); // to be decided
	while (!is_dead(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (arg);
}

int	thread(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	monitor;
	int			i;

	if (pthread_create(&monitor, NULL, &observe, table->philos) != 0)
		return (1); // cleanup
	i = -1;
	while (++i < table->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine, &table->philos[i] != 0))
			return (1); // cleanup
	}
	if (pthread_join(monitor, NULL) != 0)
		return (1); //cleanup
	i = -1;
	while (++i < table->num_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (1); //cleanup
	}
}
