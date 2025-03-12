/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:24 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 13:44:12 by ruzhang          ###   ########.fr       */
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

void	exec_one_builtin(t_pipeline *pipeline, t_program *minishell, t_command *cmd)
{
	int	saved_in;
	int	saved_out;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	if (process_redirections(cmd->redirections, minishell))
		return ;
	exec_builtin(cmd->args, minishell, pipeline->num_cmds);
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_in);
	close(saved_out);
	if (minishell->exit)
		exit(minishell->status);
}

void	close_fds(t_pipex *p)
{
	if (p->prev_fd > -1)
		close(p->prev_fd);
	if (p->cur_pipefd[0] > -1)
		close(p->cur_pipefd[0]);
	if (p->cur_pipefd[1] > -1)
		close(p->cur_pipefd[1]);
}

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
		exec_one_builtin(pipeline, minishell, pipeline->cmd);
		free_pipeline(pipeline);
		return ;
	}
	process(pipeline, minishell, &p);
	wait_and_clean(pipeline, minishell, &p);
}

void	wait_and_clean(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	int	i;
	int	status;
	int	sig;

	i = -1;
	status = 0;
	while (++i < pipeline->num_cmds)
	{	
		waitpid(p->pids[i], &status, 0);
	}
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
	// close_fds(p);
	free(p->pids);
	free_pipeline(pipeline);
}
