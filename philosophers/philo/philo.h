/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:58:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/21 17:26:37 by ruzhang          ###   ########.fr       */
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
	int				num_philos; // av[1]
	size_t			time_to_die; // av[2];
	size_t			time_to_eat; // av[3];
	size_t			time_to_sleep; // av[4];
	int				num_times_must_eat; // av[5] ? av[5] : -1
	size_t			start_time;
	size_t			last_meal; // time when starting to eat
	int				meals_eaten;
	int				*dead;

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*eat_lock;
	pthread_mutex_t	*finish_lock;
}	t_philo;

// finish_lock - if (has_dead(philo) || all_ate(philos))
typedef struct s_table
{
	int				is_dead;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	finish_lock;
	t_philo			*philos;
}	t_table;

// input.c
int	check_input(char **av);
int	ft_atoi(const char *nptr);

void	init_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks, char **av);
void	init_forks(pthread_mutex_t *forks, int num_forks);
void	init_table(t_table *table, t_philo *philos);


// utils.c
size_t	get_current_time(void);
void	ft_usleep(size_t milliseconds);

// threads.c
void	*routine(void *arg);
void	thread(t_table *table, pthread_mutex_t *forks);
void	cleanup(char *message, t_table *table, pthread_mutex_t *forks);

// monitor.c
void	write_message(char *message, t_philo *philo, int id);
void	*monitor(void *arg);
int	philo_is_dead(t_philo *philo);

// routine.c
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);

#endif