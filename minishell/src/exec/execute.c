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

void	check_execute(char **args, char **envp, char **paths, t_pipex *p)
{
	if (access(args[0], F_OK) == 0)
	{
		if (access(args[0], X_OK) == -1)
		{
			ft_putendl_fd("Command no permission", 2);
			cleanup();
			exit(126);
		}
		if (execve(args[0], args, envp) == -1)
		{
			ft_putendl_fd("Command no permission", 2);
			cleanup();
			exit(1);
		}
	}
}

char	**parse_path(t_env *envlst, t_pipex *p)
{
	char	**paths;

	paths = NULL;
	paths = ft_split(get_var_value("PATH", envlst), ':');
	if (!paths || !*paths)
	{
		ft_putendl_fd("Command not found", 2);
		cleanup();
		exit(127);
	}
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

void	execute(t_program *minishell, t_pipeline *pipeline, char **args, t_pipex *p)
{
	char	**args;
	char	**paths;
	int		i;

	if ((!args || !*args) && (access("", F_OK) == -1))
	{
		ft_putendl_fd("Command not found", 2);
		cleanup();
		exit(127);
	}
	check_execute(args, minishell->envp, NULL, p);
	paths = parse_path(minishell->envlst, p);
	i = -1;
	while (paths[++i])
	{
		free(args[0]);
		args[0] = join_str(paths[i], args[0]);
		check_execute(args, minishell->envp, paths, p);
	}
	ft_putendl_fd("Command not found", 2);
	cleanup();
	exit(127);
}
