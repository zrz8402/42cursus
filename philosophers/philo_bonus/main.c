/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:19:50 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/28 16:25:01 by ruzhang          ###   ########.fr       */
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
		return (1);
	table->pids = malloc(sizeof(pid_t) * table->num_philos);
	if (!table->pids)
	{
		cleanup(table);
		return (1);
	}
	return (0);
}

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
			cleanup(table);
	}
	return (arg);
}

void	process(t_table *table)
{
	int			i;
	pthread_t	meal_check;

	i = -1;
	if (table->num_times_must_eat > 0)
	{
		if (pthread_create(&meal_check, NULL, &check_meals, table) != 0)
			cleanup(table); // to be fixed
		pthread_detach(&meal_check);
	}
	
	while (++i < table->num_philos)
	{
		table->pids[i] = fork();
		if (table->pids[i] == -1)
		{
			while (--i >= 0)
				kill(table->pids[i], SIGKILL);
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
	if (init_table(&table, av))
		return (1);
	process(&table);
	wait_exit(&table);
	cleanup(&table);
	return (0);
}
