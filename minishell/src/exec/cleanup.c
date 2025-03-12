/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:19:16 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 15:19:46 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(t_pipex *p)
{
	if (p->prev_fd > -1)
		close(p->prev_fd);
	if (p->cur_pipefd[0] > -1)
		close(p->cur_pipefd[0]);
	if (p->cur_pipefd[1] > -1)
		close(p->cur_pipefd[1]);
}

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
		if (sig == SIGINT)
		{
			write(1, "\n", 1);
			minishell->status = sig;
		}
		else if (sig == SIGQUIT)
		{
			write(1, "Quit (core dumped)\n", 19);
			minishell->status = sig + 128;
		}
	}
	free(p->pids);
	free_pipeline(pipeline);
}
