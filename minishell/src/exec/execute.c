/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:26:03 by  ruzhang          #+#    #+#             */
/*   Updated: 2025/03/22 13:26:55 by ruzhang          ###   ########.fr       */
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

int	is_dir(char *path)
{
	struct stat	info;

	if (stat(path, &info))
		return (0);
	if (S_ISDIR(info.st_mode))
		return (1);
	return (0);
}

int	check_execute(char **args, t_program *minishell)
{
	if (ft_strncmp(args[0], "./", 2) == 0 || ft_strncmp(args[0], "/", 1) == 0)
	{
		if (access(args[0], F_OK) == -1)
			return (ft_error(args[0], FILE_NOT_FOUND, minishell, 127), 1);
		if (is_dir(args[0]))
			return (ft_error(args[0], IS_DIR, minishell, 126), 1);
		if (access(args[0], X_OK) == -1)
			return (ft_error(args[0], NO_PERMISSION, minishell, 126), 1);
		if (execve(args[0], args, minishell->envp) == -1)
			return (ft_error(args[0], CMD_NOT_FOUND, minishell, 127), 1);
	}
	if (access(args[0], F_OK) == 0)
		execve(args[0], args, minishell->envp);
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
		if (access(args[0], F_OK) == 0)
			execve(args[0], args, minishell->envp);
	}
	free(args[0]);
	free_arr(paths);
	ft_error(tmp, CMD_NOT_FOUND, minishell, 127);
	free(tmp);
	return (0);
}

void	execute(t_program *minishell, char **args)
{
	char	*path;

	if (!args || !*args)
		return ;
	if (ft_strcmp(args[0], "") == 0)
		return (ft_error("", CMD_NOT_FOUND, minishell, 127));
	if (check_execute(args, minishell))
		return ;
	path = get_var_value("PATH", minishell->envlst);
	if (!path || !*path)
		return (ft_error(args[0], CMD_NOT_FOUND, minishell, 127));
	check_exec_with_path(args, minishell);
}
