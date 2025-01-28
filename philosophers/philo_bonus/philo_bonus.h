/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:19:47 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/28 12:54:36 by ruzhang          ###   ########.fr       */
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
	int		*dead;
	int		*all_ate;

	sem_t	*fork_sem;
	sem_t	*write_sem;
}	t_philo;

typedef struct s_table
{
	int			num_philos;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	int			num_times_must_eat;
	int			all_ate;
	sem_t		*fork_sem;
	sem_t		*write_sem;
	t_philo		*philos;
	pid_t		*pids;
}	t_table;


// utils.c
int		ft_atoi(const char *nptr);
int		check_input(char **av);
size_t	get_current_time(void);
void	ft_usleep(size_t milliseconds);

#endif