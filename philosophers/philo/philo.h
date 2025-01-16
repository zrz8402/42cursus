/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:58:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/16 14:05:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define MAX_PHILO 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				start_time;
	int				time_to_die; // av[2] * 1000;
	int				time_to_eat; // av[3] * 1000;
	int				time_to_sleep; // av[4] * 1000;
	int				num_times_must_eat; // av[5] ? av[5] : -1
	int				meals_eaten;
	int				last_meal;

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*eat_lock;
	pthread_mutex_t	*dead_lock;
}	t_philo;

typedef struct s_table
{
	int	num_philos; // av[1]
	pthread_mutex_t	write_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philos;
}	t_table;

// input.c
int	check_input(char **av);

// utils.c
size_t	get_current_time(void);
void	ft_usleep(size_t milliseconds);

// threads.c
void	*routine(void *arg);
int	thread(t_table *table, pthread_mutex_t *forks);

// monitor.c
void	write_message(char *message, t_philo *philo, int id);
void	*observe(void *arg);


// routine.c
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);

#endif