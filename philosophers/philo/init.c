/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:53 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/21 12:31:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks, char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].num_philos = ft_atoi(av[1]);
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			philos[i].num_times_must_eat = ft_atoi(av[5]);
		else
			philos[i].num_times_must_eat = -1;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = philos[i].start_time;
		philos[i].meals_eaten = 0;
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + philos[i].num_philos - 1) % philos[i].num_philos];
		philos[i].dead = table->is_dead;
		philos[i].write_lock = &table->write_lock;
		philos[i].eat_lock = &table->eat_lock;
		philos[i].finish_lock = &table->finish_lock;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_forks)
{
	int	i;

	i = -1;
	while (++i < num_forks)
		pthread_mutex_init(&forks[i], NULL);	
}

void	init_table(t_table *table, t_philo *philos)
{
	table->is_dead = 0;
	table->philos = philos;
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->eat_lock, NULL);
	pthread_mutex_init(&table->finish_lock, NULL);	
}
