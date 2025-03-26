/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_make.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:50:45 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/26 17:15:01 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_command	*init_command_node(t_program *minishell);
void		append_command(t_command **cmd_list, t_command *new_cmd);

// FUNCTION get_commands
// Processes a lex list of typed instruction tokens into a command list.
//
// A command list is a linked list with the following node members:
// - char **args = 2d array of arguments, starting with command
// - t_redir *redirections = linked list of redirections
// - t_command *next = pointer to next command node
//
// Redirections are represented as a linked list with the following members:
// - e_ltype type = the type of redirection (RED_IN, APPEND, etc)
// - char *file = the target/source file name (NULL for HEREDOC)
// - int heredoc_fd = the fd for a HEREDOC (-1 for non-HEREDOC)
// - t_redir *next = pointer to next redirection
//
// If there are any errors in allocating memory for arguments or redirections
// the minishell status is set to != 0, and the command list is returned
// as NULL for downstream error handling.
//
// @param input_lex = t_lex linked list of typed instruction tokens
// @param minishell = minishell struct containing status
//
// @return a pointer to a t_command command list 
t_command	*get_commands(t_lex *input_lex, t_program *minishell)
{
	int			num_cmds;
	t_lex		*cmd_tokens;
	t_command	*cmd_list;
	t_command	*new_cmd;

	cmd_tokens = input_lex;
	cmd_list = NULL;
	num_cmds = count_commands(input_lex);
	while (!(minishell->status) && cmd_tokens && num_cmds--)
	{
		new_cmd = init_command_node(minishell);
		if (!new_cmd)
			return (free_command_list(cmd_list));
		append_command(&cmd_list, new_cmd);
		add_args(new_cmd, cmd_tokens, minishell);
		add_redirs(new_cmd, cmd_tokens, minishell);
		while (cmd_tokens && cmd_tokens->type != PIPE)
			cmd_tokens = cmd_tokens->next_lex;
		if (cmd_tokens && cmd_tokens->type == PIPE)
			cmd_tokens = cmd_tokens->next_lex;
	}
	if (minishell->status != 0)
		return (free_command_list(cmd_list));
	return (cmd_list);
}

// FUNCTION count_commands
// Use number of pipes as a proxy for the number of commands; some
// instructions might have no COMMAND type tokens (e.g. `<< EOF`).
int	count_commands(t_lex *input_lex)
{
	int	num_cmds;

	if (!input_lex)
		return (0);
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
//
// @return the new node if successful
// @return NULL (and set minishell status to 1) if memory allocation fails
t_command	*init_command_node(t_program *minishell)
{
	t_command	*new_cmd;

	new_cmd = (t_command *)malloc(sizeof(t_command));
	if (!new_cmd)
	{
		minishell->status = 1;
		return (NULL);
	}
	new_cmd->args = NULL;
	new_cmd->redirections = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

// FUNCTION append_command
// Append a new t_command node to the end of a command linked list.
void	append_command(t_command **cmd_list, t_command *new_cmd)
{
	t_command	*cmd_ptr;

	if (!(*cmd_list))
	{
		(*cmd_list) = new_cmd;
		return ;
	}
	cmd_ptr = (*cmd_list);
	while (cmd_ptr->next)
		cmd_ptr = cmd_ptr->next;
	cmd_ptr->next = new_cmd;
}

// FUNCTION free_command_list
// Free memory allocated to a command linked list (including the two
// members of each node that can contain allocated memory:
// - char **args = 2d array of arguments, starting with command
// - t_redir *redirs = linked list of redirections
//
// Set the t_command argument to NULL and return it once all memory is freed.
t_command	*free_command_list(t_command *cmd_list)
{
	t_command	*cmd_ptr;

	cmd_ptr = cmd_list;
	while (cmd_ptr)
	{
		free_command_args(cmd_ptr->args);
		free_command_redirs(cmd_ptr->redirections);
		cmd_ptr = cmd_ptr->next;
		free(cmd_list);
		cmd_list = cmd_ptr;
	}
	return (cmd_list);
}
