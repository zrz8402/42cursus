/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_arg_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:50:45 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/20 15:13:39 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		count_args(t_lex *tok_ptr);
char	**get_cmd_args(t_lex *tok_ptr, char **args, int num_args);

// FUNCTION add_cmd_args
// Add a char** array of arguments (including the command as the first element)
// as the arg member of a t_command node, if the t_command node exists.
//
// For commands with no commands or command arguments (e.g. `<< EOF` the arg
// member of the command node should be NULL. 
//
// If there are errors with memory allocation, set the minishell status to 1.
//
// @param cmd_node = pointer to t_command node
// @param tok_ptr = pointer to t_lex node at start of series of command tokens
// @param mshell = pointer to minishell struct containing status
void	add_cmd_args(t_command *cmd_node, t_lex *tok_ptr, t_program *mshell)
{
	int		num_args;

	num_args = count_args(tok_ptr);
	if (num_args == 0)
		return ;
	cmd_node->args = (char **)malloc(sizeof(char *) * (num_args + 1));
	if (!(cmd_node->args))
	{
		mshell->status = 1;
		return ;
	}
	cmd_node->args = get_cmd_args(tok_ptr, cmd_node->args, num_args);
	if (!(cmd_node->args))
	{
		mshell->status = 1;
		return ;
	}
}

// FUNCTION count_args
// Count the arguments in a series of arguments in a command (possibly 
// delimited by a pipe); ignore the arguments that are target/source filenames 
// for redirections, but include the COMMAND token.
//
// @param tok_ptr = pointer to t_lex node at start of series of command tokens
// 
// @return the number of command arguments (not including redirection arguments)
int	count_args(t_lex *tok_ptr)
{
	int				num_cmd_args;
	enum e_ltype	ty;

	if (tok_ptr && tok_ptr->type == PIPE)
		tok_ptr = tok_ptr->next_lex;
	num_cmd_args = 0;
	while (tok_ptr && tok_ptr->type != PIPE)
	{
		ty = tok_ptr->type;
		if (ty == RED_IN || ty == RED_OUT || ty == APPEND || ty == HEREDOC)
			tok_ptr = tok_ptr->next_lex;
		else if (tok_ptr->type == COMMAND || tok_ptr->type == ARGUMENT)
			num_cmd_args++;
		if (tok_ptr)
			tok_ptr = tok_ptr->next_lex;
	}
	return (num_cmd_args);
}

// FUNCTION get_cmd_args
// Get the arguments (including the command, empty string if non-existant) in a
// series of arguments in a command (possibly delimited by a pipe); fill up the 
// char** array, terminating the first array with a NULL.
//
// For commands with no commands or command arguments (e.g. `<< EOF` the arg
// member of the command node should be NULL. 
//
// @param tok_ptr = pointer to t_lex node at start of series of command tokens
// @param cmd_args = 2D char array of arguments (including COMMAND), NULL term
// @param num_args = number of command arguments, not including COMMAND token
char	**get_cmd_args(t_lex *tok_ptr, char **cmd_args, int num_args)
{
	int				i;
	enum e_ltype	ty;

	if (tok_ptr && tok_ptr->type == PIPE)
		tok_ptr = tok_ptr->next_lex;
	cmd_args[num_args] = NULL;
	i = 0;
	while (cmd_args && tok_ptr && tok_ptr->type != PIPE && i < num_args)
	{
		ty = tok_ptr->type;
		if (ty == RED_IN || ty == RED_OUT || ty == APPEND || ty == HEREDOC)
			tok_ptr = tok_ptr->next_lex;
		else if (tok_ptr->type == COMMAND || tok_ptr->type == ARGUMENT)
		{
			cmd_args[i] = ft_strdup(tok_ptr->value);
			if (!(cmd_args[i]))
				cmd_args = free_command_args(cmd_args);
			i++;
		}
		if (tok_ptr)
			tok_ptr = tok_ptr->next_lex;
	}
	return (cmd_args);
}

// FUNCTION free_command_args
// Free memory allocated to the 'args' char** array of a t_command node, and
// return the args array set to NULL.
//
// @param pointer to a t_command node with a char** args member to free 
char	**free_command_args(char **cmd_args)
{
	int		i;

	if (!cmd_args)
		return (NULL);
	i = 0;
	while (cmd_args[i])
	{
		free(cmd_args[i]);
		i++;
	}
	free(cmd_args);
	cmd_args = NULL;
	return (cmd_args);
}
