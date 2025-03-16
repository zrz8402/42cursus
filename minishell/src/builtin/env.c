/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:07:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/16 14:54:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(char *key, t_env *envlst)
{
	while (envlst)
	{
		if (ft_strcmp(key, envlst->key) == 0)
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
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

t_env	*create_node(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	update_envlst(t_env **envlst, char *key, char *value, int append)
{
	t_env	*tmp;

	if (append)
	{
		append_node(envlst, create_node(key, value));
		return ;
	}
	tmp = *envlst;
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == 0)
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
	append_node(envlst, create_node(key, value));
}

void	run_env(t_env *envlst)
{
	t_env	*tmp;

	tmp = envlst;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(tmp->value, STDOUT_FILENO);
		}
		tmp = tmp->next;
	}
}
