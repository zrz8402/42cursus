/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stimulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:49:18 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/30 13:12:57 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_meals(void *arg)
{
	t_table	*table;
	int		finished;

	finished = 0;
	table = (t_table *)arg;
	while (1)
	{
		sem_wait(table->meal_sem);
		++finished;
		if (finished >= table->num_philos)
			destroy_all(table, 1, NULL, EXIT_SUCCESS);
	}
	return (arg);
}

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

void	stimulation(t_table *table)
{
	pthread_t	meal_check;
	int			i;

	if (table->num_times_must_eat > 0)
	{
		if (pthread_create(&meal_check, NULL, &check_meals, table) != 0)
			destroy_all(table, 0, "Thread creation error", EXIT_FAILURE);
		pthread_detach(meal_check);
	}
	i = -1;
	while (++i < table->num_philos)
	{
		table->pids[i] = fork();
		if (table->pids[i] == -1)
			destroy_all(table, 1, "Fork error", EXIT_FAILURE);
		else if (table->pids[i] == 0)
			routine(table->philos[i], table);
	}
	wait_exit(table);
}
