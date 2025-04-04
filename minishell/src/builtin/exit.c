/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:27:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 22:58:18 by ruzhang          ###   ########.fr       */
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
IF VALUE(arg) is beyond LONG_MAX and AND LONG_MIN, also not numeric
If > 1 arg, first is numeric, return 1 and do not exit shell
If VALUE(arg) out of range (0-255): undefined
*/
void	run_exit(char **args, t_program *minishell)
{
	minishell->status = 0;
	minishell->exit = 1;
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (args[1])
	{
		if (!valid_arg(args[1]))
		{
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd(": numeric argument required", STDERR_FILENO);
			minishell->status = 2;
			return ;
		}
		if (args[2])
		{
			minishell->exit = 0;
			return (ft_error("exit", ": too many arguments", minishell, 1));
		}
		minishell->status = ft_atoi(args[1]);
	}
}
