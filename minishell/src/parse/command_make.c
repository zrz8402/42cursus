/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_make.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:50:45 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/15 15:05:04 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_command	*init_command_node(char **args, t_redir *redirs, t_command *next);
void		append_command(t_command **cmd_pipe, t_command *new_cmd);

// FUNCTION get_commands
// Processes a lex list of typed instruction tokens into a command pipeline.
//
// A command pipeline is a linked list with the following node members:
// - char **args = 2d array of arguments, starting with command
// - t_redir *redirs = linked list of redirections
// - t_command *next = pointer to next command node
//
// Redirections are represented as a linked list with the following members:
// - e_ltype type = the type of redirection (RED_IN, APPEND, etc)
// - char *file = the target/source file name (NULL for HEREDOC)
// - int heredoc_fd = the fd for a HEREDOC (-1 for non-HEREDOC)
// - t_redir *next = pointer to next redirection
//
// @param t_lex linked list of typed instruction tokens
//
// @return a pointer to a t_command command pipeline
t_command	*get_commands(t_lex *input_lex)
{
	int			num_cmds;
	t_lex		*cmd_tokens;
	t_command	*cmd_list;
	t_command	*new_cmd;

	cmd_tokens = input_lex;
	cmd_list = NULL;
	num_cmds = count_commands(input_lex);

	// printf("num_cmds = %i\n\n", num_cmds);

	while (cmd_tokens && num_cmds--)
	{
		new_cmd = init_command_node(NULL, NULL, NULL);
		append_command(&cmd_list, new_cmd);
		add_command_args(new_cmd, cmd_tokens);
		add_command_redirs(new_cmd, cmd_tokens);
		while (cmd_tokens && cmd_tokens->type != PIPE)
			cmd_tokens = cmd_tokens->next_lex;
		if (cmd_tokens && cmd_tokens->type == PIPE)
			cmd_tokens = cmd_tokens->next_lex;
	}
	return (cmd_list);
}

// FUNCTION count_commands
// Use number of pipes as a proxy for the number of commands; some
// instructions might have no COMMAND type token...?
int	count_commands(t_lex *input_lex)
{
	int	num_cmds;

	num_cmds = 1;
	while (input_lex->next_lex)
	{
		if (input_lex->type == PIPE)
			num_cmds++;
		input_lex = input_lex->next_lex;
	}
	return (num_cmds);
}

// FUNCTION init_command_node
// Initialize a new t_command node
t_command	*init_command_node(char **args, t_redir *redirs, t_command *next)
{
	t_command	*new_cmd;

	new_cmd = (t_command *)malloc(sizeof(t_command));
	if (!new_cmd)
		printf("Error in init_command_node: EXIT GRACEFULLY!!\n");

	new_cmd->args = args,
	new_cmd->redirections = redirs;
	new_cmd->next = next;

	return (new_cmd);
}

// FUNCTION append_command
// Append a new t_command node to the end of a command pipeline linked list.
void	append_command(t_command **cmd_pipe, t_command *new_cmd)
{
	t_command	*cmd_ptr;

	if (!(*cmd_pipe))
	{
		(*cmd_pipe) = new_cmd;
		return ;
	}
	cmd_ptr = (*cmd_pipe);
	while (cmd_ptr->next)
		cmd_ptr = cmd_ptr->next;
	cmd_ptr->next = new_cmd;
}

// FUNCTION free_command_pipe
// Free memory allocated to a command pipe linked list (including the two
// members of each node that can contain allocated memory:
// - char **args = 2d array of arguments, starting with command
// - t_redir *redirs = linked list of redirections
//
// Set the t_command argument to NULL and return it once all memory is freed.
t_command	*free_command_list(t_command *cmd_pipe)
{
	t_command	*cmd_ptr;

	cmd_ptr = cmd_pipe;
	while (cmd_ptr)
	{
		free_command_args(cmd_ptr);
		cmd_ptr->redirections = free_command_redirs(&(cmd_ptr->redirections)); // tidy up - pass cmd_ptr instead and NULL there
		cmd_ptr = cmd_ptr->next;
		free(cmd_pipe);
		cmd_pipe = cmd_ptr;
	}
	return (cmd_pipe);
}

