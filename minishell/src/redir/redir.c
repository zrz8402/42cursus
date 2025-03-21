/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:42 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/21 19:35:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_current_heredocfd(t_command *cmd)
{
	if (cmd->redirections)
	{
		while (cmd->redirections != NULL)
		{
			if (cmd->redirections->type == HEREDOC)
				close(cmd->redirections->heredoc_fd);
			cmd->redirections = cmd->redirections->next;
		}
	}
}

void	close_heredocfd(t_command *cmd)
{
	if (cmd)
	{
		while (cmd)
		{
			close_current_heredocfd(cmd);
			cmd = cmd->next;
		}
	}
}

void	close_fds(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	restore_fds(int saved_in, int saved_out)
{
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close_fds(saved_in, saved_out);
}

int	process_redirections(t_redir *redir, t_program *minishell)
{
	int	saved_in;
	int	saved_out;
	int	code;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	code = 0;
	while (redir != NULL)
	{
		if (redir->type == RED_IN)
			code = process_in(redir->file, minishell);
		else if (redir->type == RED_OUT)
			code = process_out(redir->file, minishell);
		else if (redir->type == APPEND)
			code = process_append(redir->file, minishell);
		else if (redir->type == HEREDOC)
			code = process_heredoc(redir->heredoc_fd, minishell);
		if (code)
			return (restore_fds(saved_in, saved_out), 1);
		redir = redir->next;
	}
	close_fds(saved_in, saved_out);
	return (0);
}
