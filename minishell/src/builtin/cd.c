/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:50:05 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 22:56:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home(t_program *minishell)
{
	char	*home;

	update_envlst(&minishell->envlst, "OLDPWD",
		get_var_value("PWD", minishell->envlst), 0);
	update_envp(minishell);
	home = get_var_value("HOME", minishell->envlst);
	if (!home)
		return (ft_error("cd", ": HOME not set", minishell, 1));
	if (chdir(home) != 0)
		return (ft_error("cd", ": chdir failed", minishell, 1));
	update_envlst(&minishell->envlst, "PWD", home, 0);
	update_envp(minishell);
}

void	cd_pwd(t_env *envlst)
{
	char	*cwd;
	char	buf[1024];

	cwd = getcwd(buf, sizeof(buf));
	update_envlst(&envlst, "PWD", cwd, 0);
}

/*
cd with no arg: change to home dir
cd with > 1 arg: error -too many args
cd arg:
	if success, update "OLDPWD" and "PWD"
	else, error -FILE_NOT_FOUND
*/
void	run_cd(char **args, t_program *minishell)
{
	if (!args[1])
		return (cd_home(minishell));
	if (args[1])
	{
		if (args[2])
			return (ft_error("cd", ": too many arguments", minishell, 1));
		if (chdir(args[1]) != 0)
		{
			ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putendl_fd(FILE_NOT_FOUND, STDERR_FILENO);
			minishell->status = 1;
			return ;
		}
		update_envlst(&minishell->envlst, "OLDPWD",
			get_var_value("PWD", minishell->envlst), 0);
		cd_pwd(minishell->envlst);
		update_envp(minishell);
	}
}
