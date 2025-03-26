/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 23:13:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Valid key:
Start with letters or underscore
Could contain letters, numbers and underscore
*/
int	is_valid_key(char *s)
{
	if (!ft_isalpha(*s) && *s != '_')
		return (0);
	s++;
	while (*s)
	{
		if (*s == '=')
			break ;
		if (!ft_isalnum(*s) && *s != '_')
			return (0);
		s++;
	}
	return (1);
}

int	get_envp_len(t_env *envlst)
{
	int	i;

	i = 0;
	while (envlst)
	{
		if (envlst->value)
			i++;
		envlst = envlst->next;
	}
	return (i);
}

void	update_envp(t_program *minishell)
{
	t_env	*tmp;
	int		i;
	char	**new_envp;

	i = get_envp_len(minishell->envlst);
	new_envp = malloc(sizeof(char *) * (i + 1));
	if (!new_envp)
		return ;
	tmp = minishell->envlst;
	i = 0;
	while (tmp)
	{
		if (tmp->value)
		{
			new_envp[i] = join_str(tmp->key, tmp->value, '=');
			i++;
		}
		tmp = tmp->next;
	}
	new_envp[i] = NULL;
	free_arr(minishell->envp);
	minishell->envp = new_envp;
}

void	export_var(char *s, t_program *minishell)
{
	char	*equal;
	char	*key;
	char	*value;

	equal = ft_strchr(s, '=');
	value = NULL;
	if (equal)
	{
		key = ft_substr(s, 0, equal - s);
		value = ft_strdup(equal + 1);
	}
	else
		key = ft_strdup(s);
	update_envlst(&minishell->envlst, key, value, 0);
	update_envp(minishell);
	free(key);
	if (value)
		free(value);
}

void	run_export(char **args, t_program *minishell)
{
	int		i;

	i = 0;
	if (!args[1])
		return (export_list(minishell->envlst));
	while (args[++i])
	{
		if (!is_valid_key(args[i]))
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			minishell->status = 1;
		}
		else
			export_var(args[i], minishell);
	}
	return ;
}
