/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:41:45 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/30 13:42:40 by ruzhang          ###   ########.fr       */
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
	i = -1;
	while (++i < table->num_philos)
	{
		if (table->philos[i])
			free(table->philos[i]);
	}
	if (table->philos)
		free(table->philos);
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

	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->num_times_must_eat = -1;
	if (av[5])
		table->num_times_must_eat = ft_atoi(av[5]);
	table->pids = malloc(sizeof(pid_t) * table->num_philos);
	if (!table->pids)
		destroy_all(table, 0, "Malloc error", EXIT_FAILURE);
	table->philos = (t_philo **)malloc(sizeof(t_philo *) * table->num_philos);
	if (!table->philos)
		destroy_all(table, 0, "Malloc error", EXIT_FAILURE);
	i = -1;
	while (++i < table->num_philos)
	{
		table->pids[i] = -1;
		table->philos[i] = NULL;
	}
	init_sems(table);
}

void	init_philo(t_table *table)
{
	t_philo **philos;
	int		i;

	i = -1;
	philos = table->philos;
	while (++i < table->num_philos)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			destroy_all(table, 0, "Malloc error", EXIT_FAILURE);
		philos[i]->id = i + 1;
		philos[i]->num_philos = table->num_philos;
		philos[i]->time_to_die = table->time_to_die;
		philos[i]->time_to_eat = table->time_to_eat;
		philos[i]->time_to_sleep = table->time_to_sleep;
		philos[i]->num_times_must_eat = table->num_times_must_eat;
		philos[i]->start_time = get_current_time();
		philos[i]->last_meal = get_current_time();
		philos[i]->meals_eaten = 0;
		philos[i]->fork_sem = table->fork_sem;
		philos[i]->write_sem = table->write_sem;
		philos[i]->meal_sem = table->meal_sem;
		philos[i]->death_sem = table->death_sem;
	}
}
