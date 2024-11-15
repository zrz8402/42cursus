/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:18:44 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 15:03:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	check_execute(char *path, char **args, char **envp, char **paths)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == -1)
		{
			free_arr(paths);
			free_arr(args);
			ft_error("Command no permission", 126);
		}
		if (execve(path, args, envp) == -1)
		{
			free_arr(paths);
			free_arr(args);
			ft_error("execve failed", 1);
		}
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

char	*join_str(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 + 1);
	if (!str)
		return (0);
	tmp = str;
	if (s1)
	{
		while (*s1)
			*tmp++ = *s1++;
	}
	*tmp++ = '/';
	if (s2)
	{
		while (*s2)
			*tmp++ = *s2++;
	}
	*tmp = '\0';
	return (str);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	**paths;
	char	*full;
	int		i;

	args = ft_split(cmd, ' ');
	if ((!args || !*args) && (access("", F_OK) == -1))
	{
		free_arr(args);
		ft_error("Command not found", 127);
	}
	check_execute(args[0], args, envp, NULL);
	paths = parse_path(envp);
	i = 0;
	while (paths[i])
	{
		full = join_str(paths[i], args[0]);
		check_execute(full, args, envp, paths);
		free(full);
		i++;
	}
	free_arr(args);
	free_arr(paths);
	ft_error("Command not found", 127);
}