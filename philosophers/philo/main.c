/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:52:21 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/16 11:38:28 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table			table;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if ((ac != 5 && ac != 6) || check_input(av) == -1)
	{
		// printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
		printf("Invalid args");
		return (0);
	}

	// init things
	init_table(&table, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &table, forks, av);

	// create threads
	threads(philos, &table, forks, av);
	
	// destroy threads
	cleanup(NULL, &table, forks);
}