/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:23:49 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/27 13:34:37 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Unset a variable
If env var is found, remove from envlst 
If not, ignore
*/
void	unset_var(t_env **envlst, char *key)
{
	t_env	*prev;
	t_env	*cur;

	prev = NULL;
	cur = *envlst;
	while (cur)
	{
		if (ft_strcmp(key, cur->key) == 0)
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

void	run_unset(char **args, t_program *minishell)
{
	int	i;

	if (!args[1])
		return ;
	i = 0;
	while (args[++i])
		unset_var(&minishell->envlst, args[i]);
	update_envp(minishell);
}
