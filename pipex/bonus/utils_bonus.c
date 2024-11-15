/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:50:10 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 19:20:42 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *message, int code, t_pipex *p)
{
	if (p)
	{
		if (p->pids)
			free(p->pids);
	}
	perror(message);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit(code);
}

void	f_error(char *message, int code, t_pipex *p, int fd)
{
	if (fd >= 0)
		close(fd);
	ft_error(message, code, p);
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

void	free_arr(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}
