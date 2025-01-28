/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:08:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/28 12:53:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(char *message, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (message)
		printf("%s\n", message);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->finish_lock);
	while (i < table->philos[0].num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	thread(t_table *table)
{
	pthread_t	control;
	int			i;

	if (pthread_create(&control, NULL, &monitor, table->philos) != 0)
		return (1);
	i = -1;
	while (++i < table->philos[0].num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				&routine, &table->philos[i]))
			return (1);
	}
	if (pthread_join(control, NULL) != 0)
		return (1);
	i = -1;
	while (++i < table->philos[0].num_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (1);
	}
	return (0);
}
