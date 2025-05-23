/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:19:16 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/27 13:50:00 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_and_clean(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	int	i;
	int	status;
	int	sig;

	i = -1;
	status = 0;
	while (++i < pipeline->num_cmds)
		waitpid(p->pids[i], &status, 0);
	if (WIFEXITED(status))
		minishell->status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		minishell->status = sig + 128;
		if (sig == SIGINT)
			write(1, "\n", 1);
		if (sig == SIGQUIT)
			write(1, "Quit (core dumped)\n", 19);
	}
	cleanup(NULL, pipeline, p);
	g_signal = 0;
}

void	cleanup(t_program *minishell, t_pipeline *pipeline, t_pipex *p)
{
	if (p)
	{
		if (p->pids)
			free(p->pids);
	}
	if (pipeline)
		free_command_pipe(pipeline);
	if (minishell)
		free_program(minishell);
}

void	ft_error(char *name, char *message, t_program *minishell, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(message, 2);
	minishell->status = status;
}
