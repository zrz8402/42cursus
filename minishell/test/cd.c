/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:50:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 18:16:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home(t_program *minishell)
{
	char	*home;

	update_envlst(minishell, "OLDPWD",
		get_var_value("PWD", minishell->envlst), 0);
	home = get_var_value("HOME", minishell->envlst);
	if (!home)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		minishell->exit = 1;
		return ;
	}
	if (chdir(home) != 0)
	{
		ft_putendl_fd("chdir failed", 2);
		minishell->exit = 1;
		return ;
	}
	update_envlst(minishell, "PWD", home, 0);
}

void	cd_pwd(t_program *minishell)
{
	char	*cwd;
	char	buf[1024];

	cwd = getcwd(buf, sizeof(buf));
	update_envlst(minishell, "PWD", cwd, 0);
}

void	run_cd(char **args, t_program *minishell)
{
	if (!args[1])
		return (cd_home(minishell));
	if (args[1])
	{
		if (args[2])
		{
			ft_putendl_fd("minishell: cd: too many arguments", 2);
			minishell->exit = 1;
			return ;
		}
		if (chdir(args[1]) != 0)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putendl_fd(": No such file or directory", 2);
			minishell->exit = 1;
			return ;
		}
		update_envlst(minishell, "OLDPWD",
			get_var_value("PWD", minishell->envlst), 0);
		cd_pwd(minishell);
	}
}
