/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:21:55 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/21 11:54:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// examples:
// (time) (philo_id) (message)
// (time 0) (philo_1) (has teken a fork)
// (time 0) (philo_1) (is eating)
void	write_message(char *message, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!is_dead(philo))
		printf("%zu %d %s\n", time, id, message);
	pthread_mutex_unlock(philo->write_lock);
}


int	has_dead(t_philo *philo)
{
	
}

int	all_ate(t_philo *philo)
{
	int	i;

	i = -1;
	// while (++i < philo->num_philos)
	// 	return ;
}

void	*monitor(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (has_dead(philos) == 1 || all_ate(philos) == 1)
			break ;
	}
	return (arg);
}
