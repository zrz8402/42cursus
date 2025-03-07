/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:36:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 15:09:03 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../lib/libft/libft.h"

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


typedef struct s_redir
{
	char				**redirection;
	// enum e_ltype		type;
	// char				*value;
	// int				heredoc_fd;
}	t_redir;


typedef struct s_command
{
	char				**args;
	t_redir				*redirections;
	struct s_command	*next;
}	t_command;

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


// env.c
void	init_env(t_program *minishell);
void	update_envlst(t_program *minishell, char *key, char *value, int append);
int		builtin_env(t_command *cmd, t_program *minishell);

char	*get_var_value(char *key, t_env *envlst);
t_env	*create_node(char *key, char *value);
void	append_node(t_env **envlst, t_env *new);
void	free_lst(t_env *envlst);


// process.c
void	process_pipeline(t_pipeline *pipeline, t_program *minishell);
void	process(t_pipeline *pipeline, t_program *minishell, t_pipex *p);
void	exec_one_cmd(t_pipeline *pipeline, t_program *minishell);
void	child_process(t_pipeline *pipeline, t_program *minishell, t_command *cmd, t_pipex *p);
void	parent_process(t_pipex *p, int num_cmds, t_command **cur_cmd);
void	wait_and_status();

// builtin.c
int		is_builtin(char *arg);
void	exec_builtin(t_command *cmd, t_program *minishell);

int		builtin_echo(t_command *cmd, t_program *minishell);
int		builtin_cd(t_command *cmd, t_program *minishell);
int		builtin_pwd(t_command *cmd, t_program *minishell);
int		builtin_export(t_command *cmd, t_program *minishell);
int		builtin_unset(t_command *cmd, t_program *minishell);
int		builtin_env(t_command *cmd, t_program *minishell);
int		builtin_exit(t_command *cmd, t_program *minishell);


// redir.c
void	process_in(char *file);
void	process_out(char *file);
void	process_append(char *file);
void	process_heredoc(int	heredoc_fd);
void	process_redirections(t_pipeline *pipeline, t_program *minishell);

// execute.c
void	check_execute(char **args, char **envp, char **paths, t_pipex *p);
char	**parse_path(t_env *envlst, t_pipex *p);
char	*join_str(char const *s1, char const *s2);
void	execute(t_program *minishell, t_pipeline *pipeline, char **args, t_pipex *p);

void	cleanup();
#endif