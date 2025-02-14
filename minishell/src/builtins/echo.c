/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:35:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/10 13:32:01 by ruzhang          ###   ########.fr       */
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

// suppose agrv = echo option...s text....s
int	builtin_echo(char *argv)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	while (argv[i] && with_option(argv[i]))
	{
		option = 1;
		i++;
	}
	while (argv[i])
	{
		ft_putchar_fd(argv[i], 1);
		if (argv[i + 1])
			ft_putchar_fd(" ", 1);
		i++;
	}
	if (option == 0)
		ft_putchar_fd("\n", 1);
	return (0);
}
