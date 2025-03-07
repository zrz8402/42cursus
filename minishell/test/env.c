/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:07:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 18:15:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			update_envlst(minishell, key, value, 1);
			free(value);
			free(key);
		}
	}
}

void	update_envlst(t_program *minishell, char *key, char *value, int append)
{
	t_env	*tmp;

	if (append)
	{
		append_node(&minishell->envlst, create_node(key, value));
		return ;
	}
	tmp = minishell->envlst;
	while (tmp)
	{
		if (ft_strncmp(key, tmp->key, ft_strlen(key)) == 0)
		{
			if (value)
			{
				free(tmp->value);
				tmp->value = ft_strdup(value);
			}
			return ;
		}
		tmp = tmp->next;
	}
	append_node(&minishell->envlst, create_node(key, value));
}

void	run_env(t_env *envlst)
{
	t_env	*tmp;

	tmp = envlst;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(tmp->value, 1);
		}
		tmp = tmp->next;
	}
}

// void	print_lst(t_env *envlst)
// {
// 	while (envlst)
// 	{
// 		if (envlst->value)
// 			printf("%s=%s\n", envlst->key, envlst->value);
// 		else
// 			printf("%s", envlst->key);
// 		envlst = envlst->next;
// 	}
// }
