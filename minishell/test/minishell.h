/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:36:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/07 20:39:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
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
	enum e_ltype	type;
	char			*file;
	int				heredoc_fd;
	struct s_redir	*next;
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
	int			exit;
}	t_program;


// env.c
void	init_env(t_program *minishell);
void	update_envlst(t_program *minishell, char *key, char *value, int append);
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
void	wait_and_clean(t_pipeline *pipeline, t_program *minishell, t_pipex *p);

// builtin.c
int		is_builtin(char *arg);
void	exec_builtin(char **args, t_program *minishell);

void	run_echo(char **args, t_program *minishell);
void	run_cd(char **args, t_program *minishell);
void	run_pwd(t_program *minishell);
void	run_export(char **args, t_program *minishell);
void	run_unset(char **args, t_env *envlst);
void	run_env(t_env *envlst);
void	run_exit(char **args, t_program *minishell);


// redir.c
int		process_in(char *file);
int		process_out(char *file);
int		process_append(char *file);
int		process_heredoc(int	heredoc_fd);
int		process_redirections(t_redir *redir, t_program *minishell);

// execute.c
char	*join_str(char const *s1, char const *s2);
int		check_execute(char **args, char **paths, t_program *minishell);
int		check_exec_with_path(char **args, t_program *minishell);
void	execute(t_program *minishell, char **args);

int	cleanup(t_pipeline *pipeline, t_program *minishell, t_pipex *p);
void	free_pipeline(t_pipeline *pipeline);
#endif