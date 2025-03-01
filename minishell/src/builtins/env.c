/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:07:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/01 12:21:06 by ruzhang          ###   ########.fr       */
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

t_env	*create_node(char *key, char *value)
{
	t_env *new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	append_node(t_env **envlst, t_env *new)
{
	t_env	*tmp;

	if (!*envlst)
	{
		*envlst = new;
		return ;
	}
	tmp = *envlst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	update_envlst(t_program *minishell, char *key, char *value, int append)
{
	if (append)
		append_node(&minishell->envlst, create_node(key, value));
}

void	free_lst(t_env *envlst)
{
	t_env *tmp;

	while (envlst)
	{
		tmp = envlst;
		envlst = envlst->next;
		free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

int	builtin_env(t_command *cmd, t_program *minishell)
{
	while (minishell->envlst)
	{
		if (minishell->envlst->value)
			printf("%s=%s\n", minishell->envlst->key, minishell->envlst->value);
		minishell->envlst = minishell->envlst->next;
	}
	return (0);
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
