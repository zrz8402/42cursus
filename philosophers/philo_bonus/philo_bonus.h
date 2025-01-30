/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:19:47 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/30 12:49:10 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	int		id;
	int		num_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		num_times_must_eat;
	size_t	start_time;
	size_t	last_meal;
	int		meals_eaten;
	sem_t	*fork_sem;
	sem_t	*write_sem;
	sem_t	*meal_sem;
	sem_t	*death_sem;
}	t_philo;

typedef struct s_table
{
	int			num_philos;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			num_times_must_eat;
	sem_t		*fork_sem;
	sem_t		*write_sem;
	sem_t		*meal_sem;
	sem_t		*death_sem;
	t_philo		**philos;
	pid_t		*pids;
}	t_table;

// init.c
void	destroy_all(t_table *table, int kill_child, char *message, int signal);
void	init_table(t_table *table, char **av);
void	init_philo(t_table *table);

// stimulation.c
void	stimulation(t_table *table);

// routine.c
void	routine(t_philo *philo, t_table *table);

// utils.c
int		ft_atoi(const char *nptr);
int		check_input(char **av);
size_t	get_current_time(void);
void	ft_usleep(size_t milliseconds);

#endif