/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:19:50 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/30 12:50:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_exit(t_table *table)
{
	int	i;
	int	j;
	int	status;

	i = -1;
	while (++i < table->num_philos)
	{
		waitpid(table->pids[i], &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			j = -1;
			while (++j < table->num_philos)
			{
				if (j != i)
					kill(table->pids[j], SIGKILL);
			}
			break ;
		}
	}
}

int	main(int ac, char **av)
{
	t_table			table;

	if ((ac != 5 && ac != 6) || check_input(av) == -1)
	{
		printf("Invalid args");
		return (0);
	}
	init_table(&table, av);
	init_philo(&table);
	stimulation(&table);
	// destroy_all(&table, 0, NULL, EXIT_SUCCESS);
	return (0);
}
