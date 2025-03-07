/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:24 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 14:25:40 by ruzhang          ###   ########.fr       */
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

void	exec_one_cmd(t_pipeline *pipeline, t_program *minishell)
{
	process_redirections(pipeline, minishell);
	if (is_builtin(pipeline->cmd->args[0]))
		exec_builtin(pipeline->cmd, minishell);
	else
		execute(minishell, pipeline, pipeline->cmd->args, NULL);
	cleanup();
}

void	child_process(t_pipeline *pipeline, t_program *minishell, t_command *cmd, t_pipex *p)
{
	process_redirections();
	if (p->i > 0)
		dup2(p->prev_fd, STDIN_FILENO);
	if (p->i < pipeline->num_cmds -1)
		dup2(p->cur_pipefd[1], STDIN_FILENO);
	close(p->cur_pipefd[0]);
	close(p->cur_pipefd[1]);
	if (is_builtin(cmd->args[0]))
		exec_builtin(cmd, minishell);
	else
		execute(minishell, pipeline, cmd->args, p);
}

void	parent_process(t_pipex *p, int num_cmds, t_command **cur_cmd)
{
	if (p->i != 0)
	{
		close(p->prev_fd);
		close(p->cur_pipefd[1]);
	}
	if (p->i != num_cmds)
		p->prev_fd = p->cur_pipefd[0];
	*cur_cmd = (*cur_cmd)->next;
}

void	wait_and_status()
{
	// int	i;
	// int	status;

	// i = -1;
	// while (++i < p.num_cmds)
	// 	waitpid(p.pids[i], &status, 0);

	// if (WIFEXITED(status))
	// 	exitcode = WEXITSTATUS(status);
	// else if (WIFSIGNALED(status))
	// 	exitcode = WTERMSIG(status) + 128;
}
                                                                                                                                               
void	process(t_pipeline *pipeline, t_program *minishell, t_pipex *p)
{
	int	i;
	t_command *cur_cmd;

	p->i = -1;
	p->prev_fd = 0;
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
			error("Fork failed", 1, pipeline);
			cleanup();
			exit(1);
		}
		if (p->pids[i] == 0)
			child_process(pipeline, minishell, cur_cmd, p);	
		parent_process(p, pipeline->num_cmds, &cur_cmd);
	}
}

void	run(t_pipeline *pipeline, t_program *minishell)
{
	t_pipex	p;

	if (pipeline->num_cmds == 1)
		return (exec_one_cmd(pipeline, minishell));
	process(pipeline, minishell, &p);
	wait_and_status();
	cleanup();
}
