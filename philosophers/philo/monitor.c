/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:34:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/03 11:48:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *message)
{
	long int	stamp;

	stamp = get_current_time() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->write_mutex);
	if (!finished(philo, 1) || ft_strcmp(message, "died") == 0)
		printf("%ld %d %s\n", stamp, philo->id, message);
	pthread_mutex_unlock(&philo->table->write_mutex);
}

int	finish_eating(t_philo *philo)
{
	if (philo->times_eaten == philo->table->num_must_eat)
	{
		pthread_mutex_lock(&philo->table->monitor_mutex);
		philo->table->num_finished++;
		if (philo->table->num_finished == philo->table->num_philos)
		{
			pthread_mutex_unlock(&philo->table->monitor_mutex);
			finished(philo, 0);
			return (0);
		}
		pthread_mutex_unlock(&philo->table->monitor_mutex);
		return (1);
	}
	return (1);
}

int	finished(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (status == 0)
		philo->table->stop = 1;
	if (philo->table->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
	return (0);
}

int	philo_is_dead(t_table *table, int i)
{
	pthread_mutex_lock(&table->meal_mutex);
	if (get_current_time() - table->philos[i]->last_meal_time
		>= table->time_to_die)
	{
		pthread_mutex_unlock(&table->meal_mutex);
		finished(table->philos[i], 0);
		print_status(table->philos[i], "died");
		return (1);
	}
	pthread_mutex_unlock(&table->meal_mutex);
	return (0);
}

void	*monitor(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	ft_usleep(50000);
	while (!finished(table->philos[0], 1))
	{
		i = -1;
		ft_usleep(1000);
		while (++i < table->num_philos)
		{
			if (finished(table->philos[i], 1))
				return (NULL);
			if (philo_is_dead(table, i))
				return (NULL);
		}
	}
	return (NULL);
}
