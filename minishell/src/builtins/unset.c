/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:23:49 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 15:01:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_var(t_env **envlst, char *key)
{
	t_env	*prev;
	t_env	*cur;

	prev = NULL;
	cur = *envlst;
	while (cur)
	{
		if (ft_strncmp(key, cur->key, ft_strlen(key)) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*envlst = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

int	builtin_unset(t_command *cmd, t_program *minishell)
{
	int	i;

	if (!cmd->args[1])
		return (0);
	i = 0;
	while (cmd->args[++i])
		unset_var(&minishell->envlst, cmd->args[i]);
	return (0);
}
