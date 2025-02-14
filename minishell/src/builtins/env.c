/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:07:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/10 17:24:56 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(char **env)
{
	while (*env)
	{
		ft_putchar_fd(*env, 1);
		ft_putchar_fd("\n", 1);
		env++;
	}
	// while (env_list)
	// {
	// 	if (env_list->value != NULL)
	// 		printf("%s=%s\n", env_list->key, env_list->value);
	// 	env_list = env_list->next;
	// }
	return (0);
}
