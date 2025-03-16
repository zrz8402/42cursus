/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:37:47 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/16 14:37:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *arg)
{
	if (!arg)
		return (0);
	else if (!ft_strcmp(arg, "echo") || !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "pwd") || !ft_strcmp(arg, "export")
		||!ft_strcmp(arg, "unset") ||!ft_strcmp(arg, "env")
		||!ft_strcmp(arg, "exit"))
		return (1);
	return (0);
}

void	exec_builtin(char **args, t_program *minishell, int num_cmds)
{
	if (ft_strcmp(args[0], "echo") == 0)
		run_echo(args, minishell);
	else if (ft_strcmp(args[0], "cd") == 0)
		run_cd(args, minishell);
	else if (ft_strcmp(args[0], "pwd") == 0)
		run_pwd(minishell);
	else if (ft_strcmp(args[0], "export") == 0)
		run_export(args, minishell);
	else if (ft_strcmp(args[0], "unset") == 0)
		run_unset(args, minishell->envlst);
	else if (ft_strcmp(args[0], "env") == 0)
		run_env(minishell->envlst);
	else if (ft_strcmp(args[0], "exit") == 0)
		run_exit(args, minishell, num_cmds);
}

void	exec_one_builtin(t_pipeline *pipeline, t_program *minishell)
{
	int	saved_in;
	int	saved_out;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	if (process_redirections(pipeline->cmd->redirections, minishell))
		return ;
	exec_builtin(pipeline->cmd->args, minishell, pipeline->num_cmds);
	restore_fds(saved_in, saved_out);
	if (minishell->exit)
	{
		cleanup(minishell, pipeline, NULL);
		exit(minishell->status);
	}
}
