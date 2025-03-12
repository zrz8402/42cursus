/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:07:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 13:32:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
