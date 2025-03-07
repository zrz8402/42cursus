/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:37:47 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 15:06:05 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *arg)
{
	if (!arg)
		return (0);
	else if (!strcmp(arg, "echo") || !strcmp(arg, "cd")
			|| !strcmp(arg, "pwd") || !strcmp(arg, "export")
			||!strcmp(arg, "unset") ||!strcmp(arg, "env")
			||!strcmp(arg, "exit"))
		return (1);
	return (0);
}

// passing whole program 'minishell' for now
// see how do clean up resources later
// then change the argument accordingly
// basic: cmd (+ arg)
void	exec_builtin(t_command *cmd, t_program *minishell)
{
	if (strcmp(cmd->args[0], "echo") == 0)
		builtin_echo(cmd, minishell);
	else if (strcmp(cmd->args[0], "cd") == 0)
		builtin_cd(cmd, minishell);
	else if (strcmp(cmd->args[0], "pwd") == 0)
		builtin_pwd(cmd, minishell);
	else if (strcmp(cmd->args[0], "export") == 0)
		builtin_export(cmd, minishell);
	else if (strcmp(cmd->args[0], "unset") == 0)
		builtin_unset(cmd, minishell);
	else if (strcmp(cmd->args[0], "env") == 0)
		builtin_env(cmd, minishell);
	else if (strcmp(cmd->args[0], "exit") == 0)
		builtin_exit(cmd, minishell);
}