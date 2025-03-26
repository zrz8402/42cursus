/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:24 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 23:55:32 by ruzhang          ###   ########.fr       */
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

/*

Close heredoc_fd in cmd chunks after current(if any)
Check redirections first
If rediction fails, exit the child process
Else, execute cmd
If success, do not need to free things
If not, free newly allocated memory in child process
*/
void	child_process(t_program *minishell,
	t_command *cmd, t_pipex *p, t_pipeline *pipeline)
{
	setup_child_signal();
	close_heredocfd(cmd->next);
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
	if (process_redirections(cmd->redirections, minishell))
	{
		free_program(minishell);
		exit(minishell->status);
	}
	if (cmd->args && is_builtin(cmd->args[0]))
		exec_builtin(cmd->args, minishell);
	else
		execute(minishell, cmd->args);
	free_program(minishell);
	exit(minishell->status);
}

/*
i = 0: first command, no prev_fd
i = num_cmds - 1:
	last command, no new created pipefd
	need to close prev_fd
Close heredoc_fd within that cmd chunk(if any)
So it won't be inherited by next chunk
Especially it's not needed
*/
void	parent_process(t_command **cur_cmd, t_pipex *p, int num_cmds)
{
	if (p->i != 0)
		close(p->prev_fd);
	if (p->i != num_cmds - 1)
	{
		p->prev_fd = p->cur_pipefd[0];
		close(p->cur_pipefd[1]);
	}
	close_current_heredocfd(*cur_cmd);
	*cur_cmd = (*cur_cmd)->next;
	setup_exec_signal();
}

/*
fork(): create a child process
pipe(): enables inter-process communication
	pipefd[0]: fd for reading from the pipe
	pipefd[1]: fd for writing to the pipe
*/
void	process(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	int			i;
	t_command	*cur_cmd;

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
			cleanup(minishell, pipeline, p);
			exit(1);
		}
		if (p->pids[i] == 0)
			child_process(minishell, cur_cmd, p, pipeline);
		parent_process(&cur_cmd, p, pipeline->num_cmds);
	}
}

int	init_pipex(t_pipex *p, int num_cmds)
{
	p->i = -1;
	p->prev_fd = -1;
	p->cur_pipefd[0] = -1;
	p->cur_pipefd[1] = -1;
	p->pids = malloc(num_cmds * sizeof(pid_t));
	if (!p->pids)
		return (0);
	return (1);
}

void	process_pipeline(t_pipeline *pipeline, t_program *minishell)
{
	t_pipex	p;
	char	**args;

	args = pipeline->cmd->args;
	if (pipeline->num_cmds == 1 && args && is_builtin(args[0]))
	{
		exec_one_builtin(pipeline, minishell);
		free_command_pipe(pipeline);
		return ;
	}
	if (!init_pipex(&p, pipeline->num_cmds))
	{
		cleanup(minishell, pipeline, &p);
		exit(1);
	}
	process(pipeline, minishell, &p);
	wait_and_clean(pipeline, minishell, &p);
}
