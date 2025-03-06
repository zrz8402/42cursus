/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:42 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/06 16:37:27 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_in(char *file)
{
	int	inf_fd;

	if (access(file, F_OK) == -1)
	{
		ft_putendl_fd("No infile", 2);
		cleanup(); // close fds(prev_fd, pipefd);
		exit(1);
	}
	inf_fd = open(file, O_RDONLY);
	if (inf_fd < 0)
	{
		ft_putendl_fd("Error opening input file", 2);
		cleanup();
		exit(1);
	}
	dup2(inf_fd, STDIN_FILENO);
	close(inf_fd);
}

void	process_out(char *file)
{
	int	outf_fd;

	outf_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outf_fd < 0)
	{
		ft_putendl_fd("Error opening output file", 2);
		cleanup();
		exit(1);
	}
	dup2(outf_fd, STDOUT_FILENO);
	close(outf_fd);
}

void	process_append(char *file)
{
	int	outf_fd;

	outf_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outf_fd < 0)
	{
		ft_putendl_fd("Error opening output file", 2);
		cleanup();
		exit(1);
	}
	dup2(outf_fd, STDOUT_FILENO);
	close(outf_fd);
}

void	process_heredoc(int	heredoc_fd)
{
	dup2(heredoc_fd, STDIN_FILENO);
	close(heredoc_fd);
}

void	process_redirections()
{
	// for (int i = 0; i < n; i++)
	// {
	// 	if (type == RED_IN)
	// 		process_in(file);
	// 	else if (type == RED_OUT)
	// 		process_out(file);
	// 	else if (type == APPEND)
	// 		process_append(file);
	// 	else if (type == HEREDOC)
	// 		process_heredoc(fd);	
	// }
}