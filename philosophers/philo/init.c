/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:04:33 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/03 12:06:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_table *table)
{
	int	i;

	i = -1;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (0);
	while (++i < table->num_philos)
	{
		table->forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!table->forks[i])
			return (0);
		if (pthread_mutex_init(table->forks[i], NULL) != 0)
			return (0);
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (0);
		table->philos[i]->id = i + 1;
		table->philos[i]->times_eaten = 0;
		table->philos[i]->table = table;
		if (i > 0)
			table->philos[i]->first_fork = table->forks[i - 1];
		else
			table->philos[i]->first_fork = table->forks[table->num_philos - 1];
		table->philos[i]->second_fork = table->forks[i];
		i++;
	}
	return (1);
}

int	init_table(t_table *table, char **av)
{
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]) * 1000;
	table->time_to_sleep = ft_atoi(av[4]) * 1000;
	table->stop = 0;
	if (av[5])
		table->num_must_eat = ft_atoi(av[5]);
	else
		table->num_must_eat = -1;
	table->num_finished = 0;
	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philos)
		return (0);
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->meal_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->monitor_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
		return (0);
	return (1);
}

int	init(t_table *table, char **argv)
{
	if (!init_table(table, argv))
		return (0);
	if (!init_forks(table))
		return (0);
	if (!init_philo(table))
		return (0);
	return (1);
}
