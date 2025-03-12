/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:37:36 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 13:36:16 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(char *key, t_env *envlst)
{
	while (envlst)
	{
		if (ft_strncmp(key, envlst->key, ft_strlen(key)) == 0)
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
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
