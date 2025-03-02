/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:27:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/02 15:52:09 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_arg(char *s)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s) || result > (LONG_MAX - (*s - '0')) / 10
			|| result < (LONG_MIN - 1 + (*s - '0')) / 10)
			return (0);
		result = result * 10 + sign * (*s - '0');
		s++;
	}
	return (1);
}

/*
If no arg, return exit status of last command and exit shell
If 1 arg, but not numeric, return 2 and exit shell
If > 1 arg, first is numeric, return 1 and do not exit shell
If VALUE(arg) out of range (0-255): undefined
*/
int	builtin_exit(t_command *cmd, t_program *minishell)
{
	if (cmd->args[1])
	{
		if (!valid_arg(cmd->args[1]))
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(cmd->args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			cleanup(); // need to be added
			exit(2);
		}
		if (cmd->args[2])
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: too many argument  s\n", 2);
			return (1);
		}
		minishell->status = ft_atoi(cmd->args[1]);
	}
	ft_putstr_fd("exit\n", 1);
	free_lst(minishell->envlst);
	cleanup(); // need to be added
	exit(minishell->status);
}
