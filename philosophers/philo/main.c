/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:00:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/03 11:37:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **av)
{
	t_table	table;	

	if ((argc != 5 && argc != 6) || check_input(av) == -1)
	{
		printf("Invalid args");
		return (-1);
	}
	if (!init(&table, av))
	{
		free(table.philos);
		return (1);
	}
	if (!simulation(&table))
		return (1);
	cleanup(&table);
	return (0);
}
