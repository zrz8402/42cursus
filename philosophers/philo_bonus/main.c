/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:19:50 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/26 20:00:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_table(t_table *table, int ac, char **av)
{
	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philos)
		return (1);
	
}

int	main(int ac, char **av)
{
	t_table			table;

	if ((ac != 5 && ac != 6) || check_input(av) == -1)
	{
		printf("Invalid args");
		return (0);
	}
	init_table(&table, ac, av);
}
