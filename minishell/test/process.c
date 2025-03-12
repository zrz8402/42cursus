/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:24 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 15:22:06 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:33 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/04 16:24:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_pipeline *pipeline, t_program *minishell, t_command *cmd, t_pipex *p)
{
	setup_child_signal();
	if (process_redirections(cmd->redirections, minishell))
		return (close_fds(p));
	if (p->i != 0)
	{
		dup2(p->prev_fd, STDIN_FILENO);
		close(p->prev_fd);
	}
	if (p->i != pipeline->num_cmds -1)
	{
		dup2(p->cur_pipefd[1], STDOUT_FILENO);
		close(p->cur_pipefd[0]);
		close(p->cur_pipefd[1]);
	}
	if (is_builtin(cmd->args[0]))
		exec_builtin(cmd->args, minishell, pipeline->num_cmds);
	else
		execute(minishell, cmd->args);
	free_envlst(minishell->envlst);
	exit(minishell->status);
}

void	parent_process(t_pipex *p, int num_cmds, t_command **cur_cmd)
{
	if (p->i != 0)
		close(p->prev_fd);
	if (p->i != num_cmds - 1)
	{
		p->prev_fd = p->cur_pipefd[0];
		close(p->cur_pipefd[1]);
	}
	*cur_cmd = (*cur_cmd)->next;
	setup_exec_signal();
}

void	process(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	int			i;
	t_command	*cur_cmd;

	p->i = -1;
	p->prev_fd = -1;
	p->pids = malloc(pipeline->num_cmds * sizeof(pid_t));
	cur_cmd = pipeline->cmd;
	while (++p->i < pipeline->num_cmds)
	{
		i = p->i;
		if (i < pipeline->num_cmds - 1)
			pipe(p->cur_pipefd);
		p->pids[i] = fork();
		if (p->pids[i] < 0)
		{
			ft_putendl_fd("Fork failed", STDOUT_FILENO);
			exit(1);
		}
		if (p->pids[i] == 0)
			child_process(pipeline, minishell, cur_cmd, p);
		parent_process(p, pipeline->num_cmds, &cur_cmd);
	}
}

void	process_pipeline(t_pipeline *pipeline, t_program *minishell)
{
	t_pipex	p;

	p.prev_fd = -1;
	p.cur_pipefd[0] = -1;
	p.cur_pipefd[1] = -1;
	if (pipeline->num_cmds == 1 && is_builtin(pipeline->cmd->args[0]))
	{
		exec_one_builtin(pipeline, minishell);
		free_pipeline(pipeline);
		return ;
	}
	process(pipeline, minishell, &p);
	wait_and_clean(pipeline, minishell, &p);
}
