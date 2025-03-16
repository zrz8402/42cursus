/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:35:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/16 14:54:53 by ruzhang          ###   ########.fr       */
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

void	run_echo(char **args, t_program *minishell)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	while (args[i] && with_option(args[i]))
	{
		option = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (option == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
