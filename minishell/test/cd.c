/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:50:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/09 13:01:46 by ruzhang          ###   ########.fr       */
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
		ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
		minishell->status = 1;
		return ;
	}
	if (chdir(home) != 0)
	{
		ft_putendl_fd("chdir failed", STDERR_FILENO);
		minishell->status = 1;
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
			ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
			minishell->status = 1;
			return ;
		}
		if (chdir(args[1]) != 0)
		{
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd(": No such file or directory", STDERR_FILENO);
			minishell->status = 1;
			return ;
		}
		update_envlst(minishell, "OLDPWD",
			get_var_value("PWD", minishell->envlst), 0);
		cd_pwd(minishell);
	}
}
