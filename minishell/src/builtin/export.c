/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 18:52:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_key(char *s)
{
	if (!ft_isalpha(*s) && *s != '_')
		return (0);
	s++;
	while (*s)
	{
		if (*s == '=')
			break ;
		if (!ft_isalnum(*s) || *s != '_')
			return (0);
		s++;
	}
	return (1);
}

void	sort_env_list(t_env *envlst)
{

}

void	export_list(t_env *envlst)
{
	t_env	*tmp;
	
	tmp = envlst;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "_"))
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(tmp->key, STDOUT_FILENO);
			if (tmp->value)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(tmp->value, STDOUT_FILENO);
				ft_putendl_fd("\"", STDOUT_FILENO);
			}
			else
				write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
}

void	export_var(char *s, t_env *envlst)
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
	update_envlst(&envlst, key, value, 0);
	free(key);
	if (value)
		free(value);
}

void	run_export(char **args, t_program *minishell)
{
	int		i;

	i = 0;
	if (!args[1])
		return (export_list(merge_sort(minishell->envlst)));
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
			export_var(args[i], minishell->envlst);
	}
	return ;
}
