/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:18:44 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/14 10:41:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_outfile(char *file)
{
	int	output_fd;

	if (access(file, F_OK) == -1)
	{
		output_fd = open(file, O_WRONLY | O_CREAT, 0644);
		if (output_fd < 0)
			ft_error("Failing creating output file", 1);
		close(output_fd);
	}
}

void	ft_error(char *message, int code)
{
	perror(message);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit(code);
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
