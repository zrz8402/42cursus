/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_arg_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:50:45 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/12 17:18:03 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		count_args(t_lex *tok_ptr);
void	get_cmd_args(t_lex *tok_ptr, char **args);

// FUNCTION add_command_args
// Add a char** array of arguments (including the command as the first element)
// as the arg member of a t_command node, if the t_command node exists.
//
// @param cmd_node = pointer to t_command node
// @param tok_ptr = pointer to t_lex node at start of series of command tokens
void	add_command_args(t_command *cmd_node, t_lex *tok_ptr)
{
	int		num_args;

	num_args = count_args(tok_ptr);

	cmd_node->args = (char **)malloc(sizeof(char *) * (num_args + 2));
	if (!(cmd_node->args))
		printf("ERROR in add_command_args: EXIT GRACEFULLY!!!\n");

	get_cmd_args(tok_ptr, cmd_node->args);
}

// FUNCTION count_args
// Count the arguments in a series of arguments in a command (possibly delimited by a pipe);
// ignore the arguments that are target/source filenames for redirections.
//
// @param tok_ptr = pointer to t_lex node at start of series of command tokens
// 
// @return the number of arguments
int	count_args(t_lex *tok_ptr)
{
	int				args;
	enum e_ltype	type;

	if (tok_ptr && tok_ptr->type == PIPE)
		tok_ptr = tok_ptr->next_lex;
	args = 0;
	while (tok_ptr && tok_ptr->type != PIPE)
	{
		type = tok_ptr->type;
		if (type == RED_IN || type == RED_OUT || type == APPEND || type == HEREDOC)
			tok_ptr = tok_ptr->next_lex;
		else if (tok_ptr->type == ARGUMENT)
			args++;
		if (tok_ptr)
			tok_ptr = tok_ptr->next_lex;
	}
	return (args);
}

// FUNCTION get_cmd_args
// Get the arguments (including the command, NULL if non-existant) in a series
// of arguments in a command (possibly delimited by a pipe); fill up a char**
// array, leaving the first element for the command (NULL if none).
//
// @param tok_ptr = pointer to t_lex node at start of series of command tokens
void	get_cmd_args(t_lex *tok_ptr, char **args)
{
	int				i;
	enum e_ltype	type;

	if (tok_ptr && tok_ptr->type == PIPE)
		tok_ptr = tok_ptr->next_lex;
	i = 0;
	while (tok_ptr && tok_ptr->type != PIPE)
	{
		type = tok_ptr->type;
		if (type == RED_IN || type == RED_OUT || type == APPEND || type == HEREDOC)
			tok_ptr = tok_ptr->next_lex;
		else if (tok_ptr->type == COMMAND || tok_ptr->type == ARGUMENT)
		{
			args[i] = ft_strdup(tok_ptr->value);
			i++;
		}
		if (tok_ptr)
			tok_ptr = tok_ptr->next_lex;
	}
	args[i] = NULL;
}


// CAN USE SHARED FREE ARRAY FUNCTION?

// FUNCTION free_command_args
// Free memory allocated to the 'args' char** array of a t_command node, and
// set the args member to NULL.
//
// @param pointer to a t_command node with a char** args member to free 
void	free_command_args(t_command *cmd_node)
{
	char	**args;
	int		i;

	args = cmd_node->args;
	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	cmd_node->args = NULL;
}

