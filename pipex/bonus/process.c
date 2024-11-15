/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:55:29 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 17:18:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_heredoc(int	*heredoc_fd, char *delimiter)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, delimiter, ft_strlen(delimiter))
			&& line[ft_strlen(delimiter)] == '\n')
			break ;
		write(heredoc_fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(heredoc_fd[1]);
}

void	process_heredoc(char *av, char **envp, t_pipex *p)
{
	char	*line;
	int		heredoc_fd[2];

	close(p->cur_pipe[0]);
	if (pipe(heredoc_fd) < 0)
		ft_error("Failing creating pipe", 1, p);
	get_heredoc(heredoc_fd, p->delimiter);
	if (dup2(heredoc_fd[0], STDIN_FILENO) == -1)
		ft_error("Duplicating infile fd failed", 1, p);
	close(heredoc_fd[0]);
	if (dup2(p->cur_pipe[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating pipefd failed", 1, p);
	close(p->cur_pipe[1]);
	execute(av, envp, p);
}

void	process_in(char *av, char **envp, t_pipex *p)
{
	int	inf_fd;

	if (p->is_heredoc)
		process_heredoc(av, envp, p);
	else
	{
		close(p->cur_pipe[0]);
		if (access(p->inf, F_OK) == -1)
			ft_error("No infile", 1, p);
		inf_fd = open(p->inf, O_RDONLY);
		if (inf_fd < 0)
		{
			close(p->cur_pipe[1]);
			ft_error("Error opening input file", 1, p);
		}
		if (dup2(inf_fd, STDIN_FILENO) == -1)
			ft_error("Duplicating infile fd failed", 1, p);
		close(inf_fd);
		if (dup2(p->cur_pipe[1], STDOUT_FILENO) == -1)
			ft_error("Duplicating pipefd failed", 1, p);
		close(p->cur_pipe[1]);
		execute(av, envp, p);
	}
}

void	process_out(char *av, char **envp, t_pipex *p)
{
	int	outf_fd;

	close(p->cur_pipe[1]);
	if (p->is_heredoc)
		outf_fd = open(p->outf, O_WRONLY | O_APPEND);
	else
		outf_fd = open(p->outf, O_WRONLY | O_TRUNC);
	if (outf_fd < 0)
		ft_error("Error opening output file", 1, p);
	if (dup2(outf_fd, STDOUT_FILENO) == -1)
		ft_error("Duplicating outfile fd failed", 1, p);
	close(outf_fd);
	if (dup2(p->cur_pipe[0], STDIN_FILENO) == -1)
		ft_error("Duplicating pipefd failed", 1, p);
	close(p->cur_pipe[0]);
	execute(av, envp, p);
}

void	general_process(char *av, char **envp, t_pipex *p)
{
	close(p->prev_pipe[1]);
	if (dup2(p->prev_pipe[0], STDIN_FILENO) == -1)
		ft_error("Duplicating fd failed", 1, p);
	close(p->prev_pipe[0]);
	close(p->cur_pipe[0]);
	if (dup2(p->cur_pipe[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating fd failed", 1, p);
	close(p->cur_pipe[1]);
	execute(av, envp, p);
}
