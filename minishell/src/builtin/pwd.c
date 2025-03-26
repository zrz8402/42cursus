/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:35:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 23:02:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// print the current working directory
void	run_pwd(t_program *minishell)
{
	char	*cwd;
	char	buf[1024];

	cwd = get_var_value("PWD", minishell->envlst);
	if (!cwd)
		cwd = getcwd(buf, sizeof(buf));
	if (!cwd)
	{
		minishell->status = 1;
		return ;
	}
	ft_putendl_fd(cwd, STDOUT_FILENO);
}
