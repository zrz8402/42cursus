/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/06 15:38:40 by ruzhang          ###   ########.fr       */
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
		if (!ft_isalnum(*s) || *s != '_' || *s != '$')
			return (0);
		s++;
	}
	return (1);
}

// int	is_valid_key(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!ft_isdigit(s[i]) || s[i] != '_')
// 		return (0);
// 	i++;
// 	while (s[i])
// 	{
// 		if (s[i] == '=')
// 			break ;
// 		if (!ft_isalnum(s[i]) || s[i] != '_' || s[i] != '$')
// 			return (0);
// 		i++;
// 	}
// 	return (i);
// }

char	*extract_key(char *s)
{
	char	*equal;
	char	*key;

	equal = ft_strchr(s, '=');
	if (equal)
		key = ft_substr(s, 0, equal - s);
	else
		key = ft_strdup(s);
}

char	*extract_value(char *s)
{
	
}

int	builtin_export(t_command *cmd, t_program *minishell)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (cmd->args[++i])
	{
		if (!is_valid_key(cmd->args))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd->args[1], 2);
			ft_putendl_fd("': not a valid identifier", 2);
		}
		else
		{
			key = extract_key(cmd->args);
			value  = extract_value(cmd->args);
			update_envlst(minishell, key, value, 0);
			free(key);
			free(value);
		}
	}
	return (0);
}
