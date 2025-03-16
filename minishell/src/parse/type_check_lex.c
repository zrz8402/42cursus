/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check_lex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/12 17:27:15 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// FUNCTION type_check_lex
// Finalize token typing, and check for invalid instructions
//
// @param input_lex = lex list containing tokens - all typed except COMMAND
void	type_check_lex(t_lex **input_lex)
{
	int	error;

	assign_command_type(*input_lex);
	error = 0;	
	
	// run checks for errors in instructions:
	// - no argument after redirection
	// - double pipe ignores all instructions after
	// - `< <` and `< "<"` treated differently (both errors, but different)

	if (error)
	{
		free_lex_list(*input_lex);
		*input_lex = NULL;
	}
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
		if (lex->type != ARGUMENT && (lex->value[0] == '>' || lex->value[0] == '<'))
		{
			lex = lex->next_lex;
			if (!lex->next_lex)
				return ;
			lex = lex->next_lex;
			continue;
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

