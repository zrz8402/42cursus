/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:27:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/18 14:00:34 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_arg(char *s)
{
	
}

// suppose av = exit (num)
int	builtin_exit(int ac, char **av)
{
	int	exit_code;

	if (ac == 1)
	{
		ft_putchar_fd("exit\n", 1);
		cleanup();
		exit(0);
	}
	if (ac > 2)
	{
		ft_putchar_fd("exit\n", 2);
		ft_putchar_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	if (!valid_arg(av[1]))
	{
		ft_putchar_fd("exit\n", 2);
		ft_putchar_fd("minishell: exit: ", 2);
		ft_putchar_fd(av[1], 2);	
		ft_putchar_fd(": numeric argument required\n", 2);
		cleanup();
		exit(1);
	}
	exit_code = ft_atoi(av[1]);
	ft_putchar_fd("exit\n", 1);
	cleanup();
	exit(exit_code);
}
