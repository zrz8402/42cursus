/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:42 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/14 13:48:34 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_redirections(t_redir *redir, t_program *minishell)
{
	int	saved_in;
	int	saved_out;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	while (redir != NULL)
	{
		if (redir->type == RED_IN)
			minishell->status = process_in(redir->file);
		else if (redir->type == RED_OUT)
			minishell->status = process_out(redir->file);
		else if (redir->type == APPEND)
			minishell->status = process_append(redir->file);
		else if (redir->type == HEREDOC)
			minishell->status = process_heredoc(redir->heredoc_fd);
		if (minishell->status)
		{
			dup2(saved_in, STDIN_FILENO);
			dup2(saved_out, STDOUT_FILENO);
			close(saved_in);
			close(saved_out);
			return (1);
		}
		redir = redir->next;
	}
	close(saved_in);
	close(saved_out);
	return (0);
}
