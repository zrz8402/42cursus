/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:28 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 23:57:46 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	eof(char *line, char *delimiter)
{
	if (!line)
	{
		ft_putendl_fd("minishell: warning: "
			"here-document at line 1 delimited by end-of-file"
			" (wanted `EOF')", STDOUT_FILENO);
		return (1);
	}
	if (!ft_strcmp(line, delimiter))
		return (1);
	return (0);
}

// FUNCTION expand_heredoc_var
// Expands variables in a heredoc line; variables with no value are removed
// from the returned line.
//
// If variables are (successfully) expanded, the original input string is
// freed and a replacement string is returned; if there are no variables,
// or there is an error with expanding any variables, the original input
// string is returned.
//
// @param input = input line from heredoc
// @param minishell = struct containing status
//
// @return a new string with variables expanded if successful
void	expand_heredoc_var(char **input, t_program *minishell)
{
	int		i;
	char	*temp_line;

	temp_line = ft_strdup(*input);
	i = 0;
	while (temp_line && temp_line[i])
	{
		if (temp_line[i] == '$')
			expand_inp(&temp_line, &i, 0, minishell);
		else
			i++;
	}
	if (temp_line)
	{
		free(*input);
		*input = temp_line;
	}
}

int	get_heredocfd(char *delimiter, int *heredoc_fd, t_program *minishell)
{
	int		savedin;
	char	*line;

	(void) minishell;
	savedin = dup(STDIN_FILENO);
	while (1)
	{
		line = readline("> ");
		if (g_signal == SIGINT)
		{
			close_fds(heredoc_fd[0], heredoc_fd[1]);
			dup2(savedin, STDIN_FILENO);
			close(savedin);
			return (-1);
		}
		if (eof(line, delimiter))
			break ;
		expand_heredoc_var(&line, minishell);
		write(heredoc_fd[1], line, ft_strlen(line));
		write(heredoc_fd[1], "\n", 1);
		free(line);
	}
	close_fds(heredoc_fd[1], savedin);
	return (heredoc_fd[0]);
}

int	handle_hdoc(char *delimiter, t_program *minishell)
{
	int		fd;
	int		heredoc_fd[2];

	fd = -1;
	pipe(heredoc_fd);
	setup_heredoc_signal();
	fd = get_heredocfd(delimiter, heredoc_fd, minishell);
	setup_exec_signal();
	return (fd);
}

int	process_heredoc(int heredoc_fd, t_program *minishell)
{
	(void) minishell;
	dup2(heredoc_fd, STDIN_FILENO);
	close(heredoc_fd);
	return (0);
}
