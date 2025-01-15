/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:58:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/15 16:16:24 by ruzhang          ###   ########.fr       */
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
	
}	t_philo;

typedef struct s_program
{
	int	num_philos; // av[1]
	
}	t_program;

int	check_input(char **av);


size_t	get_current_time(void);
void	ft_usleep(size_t milliseconds);

#endif