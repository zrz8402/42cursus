/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stimulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:49:18 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/30 15:00:29 by ruzhang          ###   ########.fr       */
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

// Even though SIGKILL immediately terminates the child, 
// the system still requires a waitpid() call from the parent 
// to fully remove that child's entry from the process table.

void	wait_exit(t_table *table)
{
	int		i;
	pid_t		finished;
	int 		status;

	finished = waitpid(-1, &status, 0);
	i = -1;
	if (finished > 0)
	{		
		while (++i < table->num_philos)
		{
			if (table->pids[i] != finished)
				kill(table->pids[i], SIGKILL);
		}
		i = -1;
		while (++i < table->num_philos)
		{
			waitpid(table->pids[i], &status, 0);
			if (WIFEXITED(status))
				destroy_all(table, 0, NULL, EXIT_SUCCESS);
			else if (WIFSIGNALED(status))
				destroy_all(table, 0, NULL, EXIT_SUCCESS);
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
