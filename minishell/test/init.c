/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:31:37 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 15:39:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_envp(char **envp, t_program *minishell)
{
	int		i;
	char	*value;

	i = 0;
	while (envp[i])
		i++;
	minishell->envp = malloc(sizeof(char *) * (i + 1));
	if (!minishell->envp)
		return ;
	i = -1;
	while (envp[++i])
	{
		minishell->envp[i] = ft_strdup(envp[i]);
		if (ft_strncmp(envp[i], "SHLVL=", 6) == 0)
		{
			value = ft_itoa(ft_atoi(minishell->envp[i] + 6) + 1);
			free(minishell->envp[i]);
			minishell->envp[i] = ft_strjoin("SHLVL=", value);
			free(value);
		}
	}
	minishell->envp[i] = NULL;
}

void	init_env(t_program *minishell)
{
	int		i;
	char	*key;
	char	*value;
	char	*equal;

	if (!minishell->envp)
		return ;
	i = -1;
	while (minishell->envp[++i])
	{
		equal = ft_strchr(minishell->envp[i], '=');
		if (equal)
		{
			key = ft_substr(minishell->envp[i], 0, equal - minishell->envp[i]);
			value = ft_strdup(equal + 1);
			update_envlst(&minishell->envlst, key, value, 1);
			free(value);
			free(key);
		}
	}
}

void	init(t_program *minishell, char **envp)
{
	ft_memset(minishell, 0, sizeof(t_program));
	set_envp(envp, minishell);
	init_env(minishell);
}

// int	main(int ac, char **av, char **envp)
// {
// 	t_program	minishell;

// 	(void)ac;
// 	(void)av;
// 	init(&minishell, envp);
// 	free_program(&minishell);
// }
