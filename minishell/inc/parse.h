/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:54:52 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/26 09:47:21 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <unistd.h> // for write
# include <stdio.h> // for printf
# include <stdlib.h> // for malloc
# include <readline/readline.h> // for readline
# include <readline/history.h> // see man readline and man history

// Types of lexemes
enum	e_ltype
{
	COMMAND,	// Command, e.g.: "ls"
	ARGUMENT,	// Argument, e.g.: "-la", strings, filenames etc
	PIPE,		// Pipe: |
	RED_IN,		// Redirect in: <
	RED_OUT,	// Redirect out: >
	APPEND,		// Append: >>
	HEREDOC,	// Heredoc: << (needs fd_int member)
	NO_TYPE,	// Default / non-existant type
};

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_program
{
	char		**envp;
	t_env		*envlst;
	int			status;
	int			prev_status;
	int			exit;
}	t_program;

// Struct for lex lists
// A struct to hold an individual typed lexemes
//
// This struct is first used to create a linked list of lexemes
//   in order of appearance (in the Bash command string).
//
// type = the type of the lexeme (see e_lex_type definition)
// value = the value (string representation) of the lexeme
// fd_int = the fd in the case of a HEREDOC type (-1 default)
// next_lex = the next lexeme in a linear order of appearance
typedef struct s_lex
{
	enum e_ltype		type;
	char				*value;
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

// MAKE_LEX

int			add_lex(t_lex **root, enum e_ltype ltype, char *lex, int lex_len);
void		free_null_lex_list(t_lex **head);
int			space_pipe_redir(char input_char);
int			token_has_quotes(char *input, int tok_start);

// PARSE_PIPELINE

t_pipeline	*parse_pipeline(char **input, t_program *minishell);
void		free_null_input(char **input);
void		print_syntax_error(char *token, char *redir);
void		*parse_exit(int stat, t_program *mshell, char **inp, t_lex **lex);
t_pipeline	*free_command_pipe(t_pipeline *cmd_pipe);

// TOKENIZE

t_lex		*tokenize(char **input, t_program *minishell);

// TOKEN_UTILS

int			valid_redir_len(char *in_ptr, enum e_ltype *rtype);
int			count_var_len(char *input, int i);
int			expand_inp(char **input, int *i, int tok_len, t_program *mshell);
char		*expand_variable(char *in_ptr, t_program *mshell);
void		replace_input(char **new_str, char *input, int i, char *exp_var);

// TYPE_CHECK_LEX

void		type_check(char **input, t_lex **input_lex, t_program *minishell);
void		assign_command_type(t_lex *input_lex);

// COMMAND_MAKE

int			count_commands(t_lex *input_lex);
t_command	*get_commands(t_lex *input_lex, t_program *minishell);
t_command	*free_command_list(t_command *cmd_pipe);

// COMMAND_ARG_UTILS

int			count_args(t_lex *tok_ptr);
void		add_args(t_command *cmd_node, t_lex *tok_ptr, t_program *mshell);
char		**free_command_args(char **cmd_args);

// COMMAND_REDIR_UTILS

void		add_redirs(t_command *cmd_node, t_lex *tok_ptr, t_program *mshell);
t_redir		*free_command_redirs(t_redir *redir_list);

#endif // PARSE_H
