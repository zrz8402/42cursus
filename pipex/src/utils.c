/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:18:44 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/12 13:25:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *message, int code)
{
	perror(message);
	exit(code);
}

void	free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**parse_path(char **envp)
{
	char	**paths;

	paths = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			paths = ft_split(*envp + 5, ':');
			break ;
		}
		envp++;
	}
	return (paths);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	**paths;
	char	*full;

	args = ft_split(cmd, ' ');
	if (!*args)
		*args = " ";
	if (access(args[0], X_OK) == 0)
		execve(args[0], args, envp);
	if (access(args[0], F_OK) == 0)
		ft_error("Command exist but no permission", 126);
	paths = parse_path(envp);
	if (!paths || !*paths)
		ft_error("Command not found", 127);
	while (*paths)
	{
		full = ft_strjoin(*paths, ft_strjoin("/", args[0]));
		if (access(full, X_OK) == 0)
			execve(full, args, envp);
		free(full);
		paths++;
	}
	ft_error("Command not found", 127);
}

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
