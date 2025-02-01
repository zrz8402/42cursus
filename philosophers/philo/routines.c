/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:07:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/01 15:56:35 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo, t_table *table)
{
	// if (philo->id % 2 == 0)
	// 	ft_usleep(1);
	write_message("is thinking", philo, table);
}

void	ft_sleep(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->stop_lock);
	if (table->stop)
	{
		pthread_mutex_unlock(&table->stop_lock);
		return ;
	}
	pthread_mutex_unlock(&table->stop_lock);
	write_message("is sleeping", philo, table);
	ft_usleep(table->time_to_sleep);
}

void ft_eat(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(&table->stop_lock);
	if (table->stop)
	{
		pthread_mutex_unlock(&table->stop_lock);
		return ;
	}
	pthread_mutex_unlock(&table->stop_lock);

    if (philo->id % 2 == 0) {
        pthread_mutex_lock(philo->l_fork);
        write_message("has taken a fork", philo, table);
        pthread_mutex_lock(philo->r_fork);
        write_message("has taken a fork", philo, table);
    } else {
        pthread_mutex_lock(philo->r_fork);
        write_message("has taken a fork", philo, table);
        pthread_mutex_lock(philo->l_fork);
        write_message("has taken a fork", philo, table);
    }

    write_message("is eating", philo, table);
    pthread_mutex_lock(&philo->time_lock);
    philo->last_meal = get_current_time();
    pthread_mutex_unlock(&philo->time_lock);

    ft_usleep(table->time_to_eat);

    pthread_mutex_lock(&philo->meal_lock);
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_lock);

    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);

    if (table->num_times_must_eat != -1 && philo->meals_eaten >= table->num_times_must_eat) {
        pthread_mutex_lock(&table->stop_lock);
        table->num_finished++;
        if (table->num_finished == table->num_philos) {
            table->stop = 1;
        }
        pthread_mutex_unlock(&table->stop_lock);
    }
}
void	single_philo(t_philo *philo, t_table *table)
{
    if (table->num_philos == 1) {
		pthread_mutex_lock(philo->r_fork);
		write_message("has taken a fork", philo, table);
        ft_usleep(table->time_to_die);
        pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_lock(&table->stop_lock);
		table->stop = 1;
		pthread_mutex_unlock(&table->stop_lock);
    }
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	while (1)
	{
		// single_philo(philo, table);
		pthread_mutex_lock(&table->stop_lock);
		if (table->stop || table->num_finished >= table->num_philos)
		{
			pthread_mutex_unlock(&table->stop_lock);
			break ;
		}
		pthread_mutex_unlock(&table->stop_lock);
		ft_think(philo, table);
		ft_eat(philo, table);
		ft_sleep(philo, table);
	}
	return (NULL);
}
