/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:36:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 14:24:24 by ruzhang          ###   ########.fr       */
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

// I might use an array right now just to write process part
// anyway, it will be a linear structure easy to loop
typedef struct s_redir
{
	char				**redirection;
	// enum e_ltype		type;
	// char				*value;
	// int				heredoc_fd;
}	t_redir;

// one cmd chunk contains args([cmd, arg1, arg2]) + redirections
// args could be null(no command)
// or easier to check having a cmd as valid input is easier
// then args will always have something (flexible to change at my part)
typedef struct s_command
{
	char				**args;
	t_redir				*redirections;
	struct s_command	*next;
}	t_command;

// lex_list to cmd chunks
typedef struct s_pipeline
{
	t_command	*cmd;
	int			num_cmds;
}	t_pipeline;


typedef struct s_pipex
{
	int		i;
	int		prev_fd;
	int		cur_pipefd[2];
	pid_t	*pids;
}	t_pipex;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_program
{
	t_lex		*lex_list;
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

void	free_arr(char **s);
void	check_execute(char *path, char **args, char **envp, char **paths);
char	**parse_path(t_env *envlst);
char	*join_str(char const *s1, char const *s2);
void	execute(t_program *minishell, t_pipeline *pipeline, char **args, t_pipex *p);
void	ft_error(char *message, int code, int fd);

#endif