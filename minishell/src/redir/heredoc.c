/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:28 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/17 16:44:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_heredocfd(char *delimiter)
{
	int		heredoc_fd[2];
	char	*line;
	int		savedin = dup(STDIN_FILENO);

	pipe(heredoc_fd);
	setup_heredoc_signal();
	while (1)
	{
		line = readline("> ");
		if (g_signal == SIGINT)
		{
			close(heredoc_fd[1]);
			close(heredoc_fd[0]);
			dup2(savedin, STDIN_FILENO);
			close(savedin);
			// minishell->status = g_signal + 128;
			return (-1);
		}
		if (!line)
		{
			ft_putendl_fd(HEREDOC_EOF_WARNING, STDOUT_FILENO);
			break ;
		}
		if (!ft_strcmp(line, delimiter))
			break ;
		write(heredoc_fd[1], line, ft_strlen(line));
		write(heredoc_fd[1], "\n", 1);
		free(line);
	}
	return (heredoc_fd[0]);
}

int	handle_heredoc(char *delimiter)
{
	int	fd;

	fd = -1;
	setup_heredoc_signal();
	fd = get_heredocfd(delimiter);
	setup_exec_signal();
	return (fd);
}

int	process_heredoc(int heredoc_fd, t_program *minishell)
{
	dup2(heredoc_fd, STDIN_FILENO);
	close(heredoc_fd);
	return (0);
}
