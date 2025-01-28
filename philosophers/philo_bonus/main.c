/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:19:50 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/28 12:54:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	cleanup(t_table *table)
{
	sem_unlink("/fork");
	sem_unlink("/write");
	if (table->fork_sem != SEM_FAILED)
		sem_close(table->fork_sem);
	if (table->write_sem != SEM_FAILED)
		sem_close(table->write_sem);
	if (table->pids)
		free(table->pids);
}

int	init_table(t_table *table, char **av)
{
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->num_times_must_eat = ft_atoi(av[5]);
	else
		table->num_times_must_eat = -1;
	sem_unlink("/fork");
	sem_unlink("/write");
	table->fork_sem = sem_open("/fork", O_CREAT, 0644, table->num_philos);
	table->write_sem = sem_open("/write", O_CREAT, 0644, 1);
	if (table->fork_sem == SEM_FAILED || table->write_sem == SEM_FAILED)
	{	printf("sem\n");
		return (1);}
	table->pids = malloc(sizeof(pid_t) * table->num_philos);
	if (!table->pids)
	{
		cleanup(table);
		return (1);
	}
	return (0);
}

void	process(t_table *table)
{
	int		i;

	i = -1;
	while (++i < table->num_philos)
	{
		table->pids[i] = fork();
		if (table->pids[i] == -1)
		{
			cleanup(table);
			exit(1);
		}
		else if (table->pids[i] == 0)
		{
			init_philo();
			routine(&table->philos[i]);
			exit(0);
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
	if (init_table(&table, av))
		return (1);
	process(&table);
	wait();
	cleanup(&table);
	return (0);
}
