/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:18:44 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/12 17:22:59 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (!paths || !*paths)
		ft_error("Command not found", 127);
	return (paths);
}

void	check_execute(char *path, char **args, char **envp)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == -1)
			ft_error("Command no permission", 126);
		if (execve(path, args, envp) == -1)
		{
			free_arr(args);
			ft_error("execve failed", 1);
		}
	}
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	**paths;
	char	*full;
	char	*tmp;
	int		i;

	args = ft_split(cmd, ' ');
	if ((!args || !*args) && (access("", F_OK) == -1))
		return (free_arr(args), ft_error("Command not found", 127));
	check_execute(args[0], args, envp);
	paths = parse_path(envp);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin("/", args[0]);
		full = ft_strjoin(paths[i], tmp);
		free(tmp);
		check_execute(full, args, envp);
		free(full);
		i++;
	}
	free_arr(args);
	free_arr(paths);
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
