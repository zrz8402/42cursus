/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:50:10 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 15:31:41 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipe(int *prev_pipe, int *cur_pipe)
{
	if (prev_pipe[0] >= 0)
		close(prev_pipe[0]);
	if (prev_pipe[1] >= 0)
		close(prev_pipe[1]);
	if (cur_pipe[0] >= 0)
		close(cur_pipe[0]);
	if (cur_pipe[1] >= 0)
		close(cur_pipe[1]);
}

void	ft_error(char *message, int code, t_pipex *p)
{
	int	i;

	if (p)
	{
		close_pipe(p->prev_pipe, p->cur_pipe);
		if (p->pids)
			free(p->pids);
	}
	perror(message);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit(code);
}

void	no_outfile(char *file)
{
	int	output_fd;

	if (access(file, F_OK) == -1)
	{
		output_fd = open(file, O_WRONLY | O_CREAT, 0644);
		if (output_fd < 0)
			ft_error("Failing creating output file", 1, NULL);
		close(output_fd);
	}
}