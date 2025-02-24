/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:36:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/02/24 18:03:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_command
{
	char	**args;
	
}	t_command;

typedef struct s_program
{
	/* data */
}	t_program;



// exec_builtin.c
int		is_builtin(char *arg);
void	exec_builtin(t_command *cmd, t_program *minishell);

// builtins
int		builtin_echo(t_command *cmd, t_program *minishell);
int		builtin_cd(t_command *cmd, t_program *minishell);
int		builtin_pwd(t_command *cmd, t_program *minishell);
int		builtin_export(t_command *cmd, t_program *minishell);
int		builtin_unset(t_command *cmd, t_program *minishell);
int		builtin_env(t_command *cmd, t_program *minishell);
int		builtin_exit(t_command *cmd, t_program *minishell);
#endif