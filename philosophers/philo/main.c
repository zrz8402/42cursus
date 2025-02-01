/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:52:21 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/01 12:25:13 by ruzhang          ###   ########.fr       */
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
		printf("Invalid args");
		return (0);
	}
	init_table(&table, philos, av);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &table, forks);
	if (stimulation(&table))
	{
		cleanup(NULL, &table, forks);
		return (1);
	}	
	cleanup(NULL, &table, forks);
	return (0);
}
