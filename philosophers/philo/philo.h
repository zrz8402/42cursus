/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:05:52 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/02 18:06:00 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_PHILO 200

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_table
{
	long			start_time;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				num_finished;
	int				stop; // -> death mutex
	pthread_t		monitor;
	pthread_mutex_t	**forks;
	struct s_philo	**philos;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	eating_mutex;
	pthread_mutex_t	monitor_mutex;
	pthread_mutex_t	death_mutex;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	t_table			*table;
}	t_philo;

// init.c
int		init_forks(t_table *table);
int		init_philo(t_table *table);
int		init_table(t_table *table, char **av);
int		init(t_table *table, char **av);

// simulation.c
long	get_current_time(void);
void	cleanup(t_table *table);
int		simulation(t_table *table);

// monitor.c
void	to_log(t_philo *philo, char *message);
int		get_status(t_philo *philo);
int		finished(t_philo *philo, int status);
int		philo_is_dead(t_table *table, int i);
void	*monitor(void *arg);

// routine.c
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	*routine(void *arg);

//utils
int		ft_atoi(const char *nptr);
int		check_input(char **av);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_usleep(long int time_in_microseconds);

#endif