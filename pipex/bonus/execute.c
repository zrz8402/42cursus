/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:25:31 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 18:30:09 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_pure_execute(char **args, char **envp, t_pipex *p)
{
	if (access(args[0], F_OK) == 0)
	{
		if (access(args[0], X_OK) == -1)
		{
			free_arr(args);
			ft_error("Command no permission", 126, p);
		}
		if (execve(args[0], args, envp) == -1)
		{
			free_arr(args);
			ft_error("execve failed", 1, p);
		}
	}
}

void	check_execute(char **args, char **envp, char **paths, t_pipex *p)
{
	if (access(p->cmd, F_OK) == 0)
	{
		if (access(p->cmd, X_OK) == -1)
		{
			free(p->cmd);
			free_arr(paths);
			free_arr(args);
			ft_error("Command no permission", 126, p);
		}
		if (execve(p->cmd, args, envp) == -1)
		{
			free(p->cmd);
			free_arr(paths);
			free_arr(args);
			ft_error("execve failed", 1, p);
		}
	}
}

char	**parse_path(char **envp, t_pipex *p)
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
		ft_error("Command not found", 127, p);
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

void	execute(char *cmd, char **envp, t_pipex *p)
{
	char	**args;
	char	**paths;
	int		i;

	args = ft_split(cmd, ' ');
	if ((!args || !*args) && (access("", F_OK) == -1))
	{
		free_arr(args);
		ft_error("Command not found", 127, p);
	}
	check_pure_execute(args, envp, p);
	paths = parse_path(envp, p);
	i = 0;
	while (paths[i])
	{
		p->cmd = join_str(paths[i], args[0]);
		check_execute(args, envp, paths, p);
		free(p->cmd);
		i++;
	}
	free_arr(args);
	free_arr(paths);
	ft_error("Command not found", 127, p);
}
