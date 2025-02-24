/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:23:49 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/24 13:02:17 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// suppose argv = unset arg1 arg2
int	builtin_unset(t_command *cmd, t_program *minishell)
{
	int	i;

	if (!cmd->args[1])
		return (0);
	i = 0;
	while (cmd->args[++i])
	{
		unset_env(); // remove from env_lsit
	}
	return (0);
}
