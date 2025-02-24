/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:27:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/24 13:02:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_arg(char *s)
{
	
}

// suppose av = exit (num)
int	builtin_exit(t_command *cmd, t_program *minishell)
{
	int	exit_code;
	int ac;
	
	// ac = len(cmd->args);
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
	if (!valid_arg(cmd->args[1]))
	{
		ft_putchar_fd("exit\n", 2);
		ft_putchar_fd("minishell: exit: ", 2);
		ft_putchar_fd(cmd->args[1], 2);	
		ft_putchar_fd(": numeric argument required\n", 2);
		cleanup();
		exit(1);
	}
	exit_code = ft_atoi(cmd->args[1]);
	ft_putchar_fd("exit\n", 1);
	cleanup();
	exit(exit_code);
}
