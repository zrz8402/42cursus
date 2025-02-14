/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:23:49 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/10 14:16:02 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// suppose argv = unset arg1 arg2
int	builtin_unset(char **argv)
{
	int	i;

	if (!argv[1])
		return (0);
	i = 0;
	while (argv[++i])
	{
		unset_env(); // remove from env_lsit
	}
	return (0);
}
