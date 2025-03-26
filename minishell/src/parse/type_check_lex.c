/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check_lex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/26 17:11:12 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_redirection(t_lex *lex_ptr);
int	check_valid_redir(t_lex *lex_ptr);
int	check_valid_pipe(t_lex *input_lex);

// FUNCTION type_check
// Finalize token typing, and check for invalid instructions
//
// Run checks for errors in instructions:
// - must have argument after redirection
// - must be something before and after pipes
// - double pipe is OR.. treat as double pipe with nothing between: status 2 
// - `< <` and `< "<"` treated differently (both errors, but different)
//
// When an invalid instruction is found, the error message for the first error
// is printed, and the rest of the instruction is ignored.
//
// @parm input = input string (free and NULL if invalid)
// @param input_lex = lex list containing tokens - all typed except COMMAND
// @param minishell = struct containing the exit status
void	type_check(char **input, t_lex **input_lex, t_program *minishell)
{
	t_lex	*lex_ptr;
	int		valid;

	assign_command_type(*input_lex);
	lex_ptr = *input_lex;
	valid = 1;
	while (valid && lex_ptr)
	{
		if (lex_ptr && lex_ptr->type == PIPE)
		{
			print_syntax_error("|", NULL);
			valid = 0;
		}
		if (valid)
			valid = check_valid_redir(lex_ptr);
		if (valid)
			valid = check_valid_pipe(lex_ptr);
		while (lex_ptr && lex_ptr->type != PIPE)
			lex_ptr = lex_ptr->next_lex;
		if (lex_ptr)
			lex_ptr = lex_ptr->next_lex;
	}
	if (!valid)
		parse_exit(2, minishell, input, input_lex);
}

// FUNCTION is_redirection
// Check if a t_lex node token is a redirection type
// 
// @return 1 if the token is a redirection type
// @return 0 if the token is not a redirection type
int	is_redirection(t_lex *lex_ptr)
{
	if (lex_ptr->type == RED_IN)
		return (1);
	if (lex_ptr->type == RED_OUT)
		return (1);
	if (lex_ptr->type == APPEND)
		return (1);
	if (lex_ptr->type == HEREDOC)
		return (1);
	return (0);
}

// FUNCTION check_valid_redir
// Check that any redirections have arguments after. 
//
// @return 1 if the redirection has an argument 
// @return 0 if the redirection doesn't have an argument 
int	check_valid_redir(t_lex *lex_ptr)
{
	while (lex_ptr && lex_ptr->type != PIPE)
	{
		while (lex_ptr && !(is_redirection(lex_ptr)))
			lex_ptr = lex_ptr->next_lex;
		if (lex_ptr && is_redirection(lex_ptr))
		{
			lex_ptr = lex_ptr->next_lex;
			if (!lex_ptr)
			{
				print_syntax_error("newline", NULL);
				return (0);
			}
			if (lex_ptr && lex_ptr->type != ARGUMENT)
			{
				print_syntax_error(lex_ptr->value, NULL);
				return (0);
			}
		}
	}
	return (1);
}

// FUNCTION check_valid_pipe
// Check that any pipes have commands / arguments before and after.
//
// @return 1 if the pipe has arguments (at least a redirection)
// @return 0 if the redirection doesn't have arguments
int	check_valid_pipe(t_lex *lex_ptr)
{
	int	valid;

	valid = 1;
	if (!count_args(lex_ptr))
		valid = 0;
	while (lex_ptr && lex_ptr->type != PIPE)
	{
		if (is_redirection(lex_ptr))
			valid = 1;
		lex_ptr = lex_ptr->next_lex;
	}
	if (lex_ptr && lex_ptr->type == PIPE && lex_ptr->next_lex == NULL)
		valid = 0;
	if (!valid)
		print_syntax_error("|", NULL);
	return (valid);
}

// FUNCTION assign_command_type
// Assign COMMAND type to tokens based on their position; assume that the
// first ARGUMENT token in a series delimited by pipes is a COMMAND.
//
// Note that the first ARGUMENT after a redirection (<<, >>, <, >) cannot
// be a COMMAND.
//
// @param input_lex = lex list containing tokens - all typed except COMMAND
void	assign_command_type(t_lex *lex)
{
	int	command;

	command = 0;
	while (lex)
	{
		if (is_redirection(lex))
		{
			if (lex->next_lex)
				lex = lex->next_lex;
			if (!lex->next_lex)
				return ;
			lex = lex->next_lex;
			continue ;
		}
		if (!command && lex->type == ARGUMENT)
		{
			lex->type = COMMAND;
			command = 1;
		}
		if (lex->type == PIPE)
			command = 0;
		lex = lex->next_lex;
	}
}
