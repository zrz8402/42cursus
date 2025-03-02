/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:36:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/02 13:28:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

# define LONG_MAX 9223372036854775807
# define LONG_MIN -9223372036854775807

enum	e_ltype
{
	COMMAND,
	ARGUMENT,
	PIPE,
	RED_IN,
	RED_OUT,
	APPEND,
	HEREDOC,
	NO_TYPE,
};

typedef struct s_lex
{
	enum e_ltype		type;
	char				*value;
	int					fd_int;
	struct s_lex		*next_lex;
}						t_lex;

typedef struct s_command
{
	char	**args;
	
}	t_command;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_program
{
	t_lex		*lex_list;
	t_command	*cmd;
	char		**envp;
	t_env		*envlst;
	int			status;
	int			exit;
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

void	init_env(t_program *minishell);
void	update_envlst(t_program *minishell, char *key, char *value, int append);
void	free_lst(t_env *envlst);
char	*get_var_value(char *key, t_env *envlst);
#endif