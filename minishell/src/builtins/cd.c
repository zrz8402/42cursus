/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:50:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/02 14:12:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_home(t_program *minishell)
{
	char	*home;

	update_envlst(minishell, "OLDPWD",
		get_var_value("PWD", minishell->envlst), 0);
	home = get_var_value("HOME", minishell->envlst);
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) != 0)
	{
		ft_putstr_fd("chdir failed", 2);
		return (1);
	}
	update_envlst(minishell, "PWD", home, 0);
	return (0);
}

int	cd_pwd(t_program *minishell)
{
	char	*cwd;
	char	buf[1024];

	cwd = getcwd(buf, sizeof(buf));
	update_envlst(minishell, "PWD", cwd, 0);
	return (0);
}

int	builtin_cd(t_command *cmd, t_program *minishell)
{
	if (!cmd->args[1])
		return (cd_home(minishell));
	if (cmd->args[1])
	{
		if (cmd->args[2])
		{
			ft_putstr_fd("minishell: cd: too many arguments\n", 2);
			return (1);
		}
		if (chdir(cmd->args[1]) != 0)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(cmd->args[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (1);
		}
		update_envlst(minishell, "OLDPWD",
			get_var_value("PWD", minishell->envlst), 0);
		cd_pwd(minishell);
	}
	return (0);
}
