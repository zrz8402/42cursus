/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:42 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 19:55:04 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_in(char *file)
{
	int	inf_fd;

	if (access(file, F_OK) == -1)
	{
		ft_putendl_fd("No infile", 2);
		return (1);
	}
	inf_fd = open(file, O_RDONLY);
	if (inf_fd < 0)
	{
		ft_putendl_fd("Error opening input file", 2);
		return (1);
	}
	dup2(inf_fd, STDIN_FILENO);
	close(inf_fd);
	return (0);
}

int	process_out(char *file)
{
	int	outf_fd;

	outf_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outf_fd < 0)
	{
		ft_putendl_fd("Error opening output file", 2);
		return (1);
	}
	dup2(outf_fd, STDOUT_FILENO);
	close(outf_fd);
	return (0);
}

int	process_append(char *file)
{
	int	outf_fd;

	outf_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outf_fd < 0)
	{
		ft_putendl_fd("Error opening output file", 2);
		return (0);
	}
	dup2(outf_fd, STDOUT_FILENO);
	close(outf_fd);
	return (0);
}

int	process_heredoc(int	heredoc_fd)
{
	dup2(heredoc_fd, STDIN_FILENO);
	close(heredoc_fd);
	return (0);
}

int	process_redirections(t_redir *redir, t_program *minishell)
{
	while (redir != NULL)
	{
		if (redir->type == RED_IN)
			minishell->exit = process_in(redir->file);
		else if (redir->type == RED_OUT)
			minishell->exit = process_out(redir->file);
		else if (redir->type == APPEND)
			minishell->exit = process_append(redir->file);
		else if (redir->type == HEREDOC)
			minishell->exit = process_heredoc(redir->heredoc_fd);
		if (minishell->exit)
			return (1);
		redir = redir->next;
	}
	return (0);
}