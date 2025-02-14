/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:50:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/10 13:32:13 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_home(void)
{
	char	*home;

	home = get_home_dir(); //get_home dir from env_list
	if (!home)
	{
		ft_putchar_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) != 0)
	{
		ft_putchar_fd("chdir failed", 2);
		return (1);
	}
	update_cwd(); // update cwd to home
	return (0);
}

// suppose argv = cd path
int	builtin_cd(char *argv, int ac)
{
	if (ac > 2)
	{
		ft_putchar_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (ac == 1)
		return (cd_home());
	if (chdir(argv[1]) != 0)
	{
		ft_putchar_fd("minishell: cd: ", 2);
		ft_putchar_fd(argv[1], 2);
		ft_putchar_fd(": No such file or directory\n", 2);
		return (1);		
	}
	update_cwd(); // update cwd to path
	return (0);
}
