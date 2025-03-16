/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:42 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/16 15:01:19 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fdup(int saved_in, int saved_out)
{
	close(saved_in);
	close(saved_out);
}

void	restore_fds(int saved_in, int saved_out)
{
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close_fdup(saved_in, saved_out);
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
	close_fdup(saved_in, saved_out);
	return (0);
}
