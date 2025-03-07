/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:24 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 20:47:45 by ruzhang          ###   ########.fr       */
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

// 3 cmds

// i = 0
// prev_fd = -1;
// pipe(cur_fd);

// child:
// dup(cur_fd[1], stdout);
// close(cur_fd[1]);
// close(cur_fd[0]);

// parent
// p->prev_fd = p->cur_pipefd[0];
// close(p->cur_pipefd[1]);

// i = 1
// p->prev_fd = p->cur_pipefd[0];
// pipe(cur_fd);

// child:
// dup(prev_fd, stdin);
// dup(cur_fd[1], stdout);
// close(prev_fd);
// close(cur_fd[1]);
// close(cur_fd[0]);

// parent
// close(p->prev_fd)
// p->prev_fd = p->cur_pipefd[0];
// close(p->cur_pipefd[1]);

// i = 2;
// p->prev_fd = p->cur_pipefd[0];

// child:
// dup(prev_fd, stdin);
// close(prev_fd);

// parent
// close(p->prev_fd);

void	exec_one_cmd(t_pipeline *pipeline, t_program *minishell)
{
	if (process_redirections(pipeline->cmd->redirections, minishell))
	{
		cleanup(pipeline, minishell, NULL);
		exit(1);
	}
	if (is_builtin(pipeline->cmd->args[0]))
		exec_builtin(pipeline->cmd, minishell);
	else
		execute(minishell, pipeline->cmd->args);
	cleanup(pipeline, minishell, NULL);
}

void	child_process(t_pipeline *pipeline, t_program *minishell, t_command *cmd, t_pipex *p)
{
	if (process_redirections(pipeline->cmd->redirections, minishell))
	{
		cleanup(pipeline, minishell, NULL);
		exit(1);
	}
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
		exec_builtin(cmd, minishell);
	else
		execute(minishell, cmd->args);
	cleanup(pipeline, minishell, p);
}

void	parent_process(t_pipex *p, int num_cmds, t_command **cur_cmd)
{
	if (p->i != 0)
	{
		close(p->prev_fd);
	}
	if (p->i != num_cmds - 1)
	{
		p->prev_fd = p->cur_pipefd[0];
		close(p->cur_pipefd[1]);
	}
	*cur_cmd = (*cur_cmd)->next;
}
                 
void	process(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	int	i;
	t_command *cur_cmd;

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
			ft_putendl_fd("Fork failed", 1);
			// cleanup();
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

	if (pipeline->num_cmds == 1)
		return (exec_one_cmd(pipeline, minishell));
	process(pipeline, minishell, &p);
	wait_and_clean(pipeline, minishell, &p);
}

int	cleanup(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	if (p)
	{
		if (p->prev_fd > -1)
			close(p->prev_fd);
		if (p->cur_pipefd[0] > -1)
			close(p->cur_pipefd[0]);
		if (p->cur_pipefd[1] > -1)
			close(p->cur_pipefd[1]);
		if (p->pids)
			free(p->pids);
	}
	free_lst(minishell->envlst);
	free_pipeline(pipeline);
	return (0);
}

int	wait_and_clean(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (++i < pipeline->num_cmds)
		waitpid(p->pids[i], &status, 0);

	free(p->pids);
	free_lst(minishell->envlst);
	free_pipeline(pipeline);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (0);
}