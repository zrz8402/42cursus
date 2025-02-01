/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:53 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/01 13:34:51 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < table->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = philos[i].start_time;
		philos[i].meals_eaten = 0;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[table->num_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		table->philos = philos;
		pthread_mutex_init(&philos[i].meal_lock, NULL);
		pthread_mutex_init(&philos[i].time_lock, NULL);
		philos[i].table = table;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_forks)
{
	int	i;

	i = -1;
	while (++i < num_forks)
		pthread_mutex_init(&forks[i], NULL);
}

void	init_table(t_table *table, t_philo *philos, char **av)
{
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->num_times_must_eat = -1;
	if (av[5])
		table->num_times_must_eat = ft_atoi(av[5]);
	table->stop = 0;
	table->finished = 0;
	table->philos = philos;
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->stop_lock, NULL);
	pthread_mutex_init(&table->finish_lock, NULL);
}
