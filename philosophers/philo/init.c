/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:53 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/16 10:46:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks)
{
	
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
	
}
