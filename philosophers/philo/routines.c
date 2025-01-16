/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:07:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/16 14:01:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	write_message("is thinking", philo, philo->id);
}

void	ft_sleep(t_philo *philo)
{
	write_message("is sleeping", philo, philo->id);;
	ft_usleep(philo->time_to_sleep);
}

// if (one_philo) -> one fork -> can never eat
// die after time_to_die
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	write_message("has taken a fork", philo, philo->id);
	if (1)// only one philo
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	write_message("has taken a fork", philo, philo->id);	

	write_message("is eating", philo, philo->id);
	philo->last_meal = get_current_time();
	ft_usleep(philo->time_to_eat);
	philo->meals_eaten++;

	// pthread_mutex_lock(philo->eat_lock);
	// pthread_mutex_unlock(philo->eat_lock);
	
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
