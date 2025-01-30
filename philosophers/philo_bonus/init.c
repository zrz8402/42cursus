/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:41:45 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/30 11:08:57 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	destroy_all(t_table *table, int kill_child, char *message, int signal)
{
	int	i;

	i = -1;
	if (kill_child)
	{
		while (++i < table->num_philos)
		{
			if (table->pids[i] != -1)
				kill(table->pids[i], SIGKILL);
		}
	}
	if (table->fork_sem != SEM_FAILED)
		sem_close(table->fork_sem);
	if (table->write_sem != SEM_FAILED)
		sem_close(table->write_sem);
	if (table->meal_sem != SEM_FAILED)
		sem_close(table->meal_sem);
	if (table->death_sem != SEM_FAILED)
		sem_close(table->death_sem);
	sem_unlink("/fork");
	sem_unlink("/write");
	sem_unlink("/meal");
	sem_unlink("/death");
	if (table->pids)
		free(table->pids);
	if (message)
		printf("%s\n", message);
	exit(signal);
}

void	init_sems(t_table *table)
{
	sem_unlink("/fork");
	sem_unlink("/write");
	sem_unlink("/meal");
	sem_unlink("/death");
	table->fork_sem = sem_open("/fork", O_CREAT, 0644, table->num_philos);
	table->write_sem = sem_open("/write", O_CREAT, 0644, 1);
	table->meal_sem = sem_open("/meal", O_CREAT, 0644, 0);
	table->death_sem = sem_open("/death", O_CREAT, 0644, 1);
	if (table->fork_sem == SEM_FAILED || table->write_sem == SEM_FAILED
		|| table->meal_sem == SEM_FAILED || table->death_sem == SEM_FAILED)
		destroy_all(table, 0, "Sem open error", EXIT_FAILURE);
}

void	init_table(t_table *table, char **av)
{
	int	i;

	i = -1;
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->num_times_must_eat = -1;
	if (av[5])
		table->num_times_must_eat = ft_atoi(av[5]);
	table->pids = malloc(sizeof(pid_t) * table->num_philos);
	while (++i)
		table->pids[i] = -1;
	if (!table->pids)
		destroy_all(table, 0, "Malloc error", EXIT_FAILURE);
}