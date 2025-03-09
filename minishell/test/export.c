/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/09 15:22:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_key(char *s)
{
	if (!ft_isdigit(*s) || *s != '_')
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

char	*extract_key(char *s)
{
	char	*equal;
	char	*key;

	equal = ft_strchr(s, '=');
	if (equal)
		key = ft_substr(s, 0, equal - s);
	else
		key = ft_strdup(s);
	return (key);
}

char	*extract_value(char *s)
{
}

void	run_export(char **args, t_program *minishell)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (args[++i])
	{
		if (!is_valid_key(args))
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			minishell->status = 1;
		}
		else
		{
			key = extract_key(args);
			value = extract_value(args);
			update_envlst(minishell, key, value, 0);
			free(key);
			free(value);
		}
	}
	return ;
}
