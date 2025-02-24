/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:35:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/24 12:53:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	with_option(char *s)
{
	int	i;

	if (s[0] != '-')
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(t_command *cmd, t_program *minishell)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	while (cmd->args[i] && with_option(cmd->args[i]))
	{
		option = 1;
		i++;
	}
	while (cmd->args[i])
	{
		ft_putchar_fd(cmd->args[i], 1);
		if (cmd->args[i + 1])
			ft_putchar_fd(" ", 1);
		i++;
	}
	if (option == 0)
		ft_putchar_fd("\n", 1);
	return (0);
}
