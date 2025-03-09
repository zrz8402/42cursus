/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:3q3 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/06 12:53:37 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	free_paths(char **arr)
{
	char	**tmp;

	tmp = arr;
	if (arr)
	{
		while (*arr)
		{
			free(*arr);
			arr++;
		}
		free(tmp);
	}
}

int	check_execute(char **args, char **paths, t_program *minishell)
{
	if (access(args[0], F_OK) == 0)
	{
		if (access(args[0], X_OK) == -1)
		{
			ft_putendl_fd("Command no permission", 2);
			free_paths(paths);
			minishell->status = 126;
			return (1);
		}
		if (execve(args[0], args, minishell->envp) == -1)
		{
			ft_putendl_fd("Command no permission", 2);
			free_paths(paths);
			minishell->status = 1;
			return (1);
		}
	}
	return (0);
}

int	check_exec_with_path(char **args, t_program *minishell)
{
	char	**paths;
	int		i;
	char	*tmp;

	paths = NULL;
	paths = ft_split(get_var_value("PATH", minishell->envlst), ':');
	i = -1;
	tmp = ft_strdup(args[0]);
	while (paths[++i])
	{
		free(args[0]);
		args[0] = join_str(paths[i], tmp);
		check_execute(args, paths, minishell);
	}
	ft_putendl_fd("Command not found", 2);
	minishell->status = 127;
	args[0] = tmp;
	free_paths(paths);
	return (0);
}

void	execute(t_program *minishell, char **args)
{
	char	*path;

	if ((!args || !*args) && (access("", F_OK) == -1))
	{
		ft_putendl_fd("Command not found", 2);
		minishell->status = 127;
		return ;
	}
	if (check_execute(args, NULL, minishell))
		return ;
	path = get_var_value("PATH", minishell->envlst);
	if (!path || !*path)
	{
		ft_putendl_fd("Command not found", 2);
		minishell->status = 127;
		return ;
	}
	check_exec_with_path(args, minishell);
}
