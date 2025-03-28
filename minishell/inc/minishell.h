/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:36:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/28 08:36:04 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "parse.h"

// range of exit
# define LONG_MAX 9223372036854775807
# define LONG_MIN -9223372036854775807

# define IS_DIR ": Is a directory"
# define FILE_NOT_FOUND ": No such file or directory"
# define NO_PERMISSION ": Permission denied"
# define CMD_NOT_FOUND ": command not found"

/*
extern: 
tells the compiler that the variable g_signal is declared elsewhere 
(outside this file). 
It does not allocate memory or define the variable; 
it just informs the compiler that the variable exists, 
and its definition can be found in another source file.

volatile: 
used to indicate that a variable can be changed at any time 
by something outside the current code flow 
(e.g., hardware, signals, or interrupt handlers). 
Without volatile, the compiler might optimize or cache the value of the variable, 
assuming it won't change unexpectedly.

sig_atomic_t: 
special type used for variables that need to be accessed atomically
in the context of signal handling. 
It is defined in <signal.h>. 
The type is usually an integer type (like int or volatile int)
that can safely be read or modified by signal handlers. 
Signal handlers can interrupt the normal program flow,
 and atomic operations are necessary to ensure 
 that updates to the variable are not interrupted.
*/
extern volatile sig_atomic_t	g_signal;

typedef struct s_pipex
{
	int		i;
	int		prev_fd;
	int		cur_pipefd[2];
	pid_t	*pids;
}	t_pipex;

// init.c
void	init(t_program *minishell, char **envp);
void	set_envp(char **envp, t_program *minishell);
void	init_env(t_program *minishell);

// util.c
int		ft_strcmp(const char *s1, const char *s2);
void	free_arr(char **arr);
void	free_envlst(t_env *envlst);
void	free_program(t_program *minishell);

// env.c
void	update_envlst(t_env **envlst, char *key, char *value, int append);
char	*get_var_value(char *key, t_env *envlst);

// signal.c
void	setup_prompt_signal(void);
void	setup_exec_signal(void);
void	setup_child_signal(void);
void	setup_heredoc_signal(void);

// handler.c
void	sigint_handler(int sig);
void	heredoc_handler(int sig);

// process.c
void	process_pipeline(t_pipeline *pipeline, t_program *minishell);
void	process(t_pipeline *pipeline, t_program *minishell, t_pipex *p);
void	parent_process(t_command **cur_cmd, t_pipex *p, int num_cmds);
void	child_process(t_program *minishell,
			t_command *cmd, t_pipex *p, t_pipeline *pipeline);

// redir.c
int		process_redirections(t_redir *redir, t_program *minishell);
void	close_fds(int saved_in, int saved_out);
void	restore_fds(int saved_in, int saved_out);
void	close_current_heredocfd(t_command *cmd);
void	close_heredocfd(t_command *cmd);

int		process_in(char *file, t_program *minishell);
int		process_out(char *file, t_program *minishell);
int		process_append(char *file, t_program *minishell);
int		process_heredoc(int heredoc_fd, t_program *minishell);
int		handle_hdoc(char *delimiter, t_program *minishell);

// execute.c
void	execute(t_program *minishell, char **args);
int		check_execute(char **args, t_program *minishell);
int		check_exec_with_path(char **args, t_program *minishell);
int		is_dir(char *path);

// builtin.c
int		is_builtin(char *arg);
void	exec_builtin(char **args, t_program *minishell);
void	exec_one_builtin(t_pipeline *pipeline, t_program *minishell);
char	*join_str(char const *s1, char const *s2, char sign);

void	run_echo(char **args);
void	run_cd(char **args, t_program *minishell);
void	run_pwd(t_program *minishell);
void	run_export(char **args, t_program *minishell);
void	update_envp(t_program *minishell);
void	export_list(t_env *envlst);
void	run_unset(char **args, t_program *minishell);
void	run_env(t_env *envlst);
void	run_exit(char **args, t_program *minishell);

// cleanup
void	wait_and_clean(t_pipeline *pipeline, t_program *minishell, t_pipex *p);
void	cleanup(t_program *minishell, t_pipeline *pipeline, t_pipex *p);
void	ft_error(char *name, char *message, t_program *minishell, int status);

#endif
