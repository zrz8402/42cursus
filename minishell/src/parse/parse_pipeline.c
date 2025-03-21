/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/21 12:49:44 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// FUNCTION parse_pipeline
// Function to return command pipeline linked list to be used in final progam.
//
// NB: Pass the address of the char* string from readline: the tokenize function
// modifies/replaces the provided string during expansion of variables; the 
// (possibly modifed/replaced) string will be freed and NULLed before return.
//
// @param char** string received from readline
//
// @return command pipeline with arguments and redirections
t_pipeline	*parse_pipeline(char **input, t_program *minishell) 
{
	t_lex		*input_lex;
	t_pipeline	*cmd_pipe;

	input_lex = tokenize(input, minishell);
	if (!input_lex)
		return (NULL);
	cmd_pipe = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!cmd_pipe)
	{
		exit_parsing_status(1, minishell, input, &input_lex);
		return (NULL);
	}
	else
	{
		cmd_pipe->cmd = get_commands(input_lex, minishell);
		cmd_pipe->num_cmds = count_commands(input_lex);
		free_null_lex_list(&input_lex);
	}
	if (cmd_pipe && !cmd_pipe->cmd)
	{
		cmd_pipe = free_command_pipe(cmd_pipe);
		exit_parsing_status(1, minishell, input, &input_lex);
	}
	free_null_input(input);
	return (cmd_pipe);
}

// FUNCTION free_null_input
// Free the input char* and set it to NULL.
void	free_null_input(char **input)
{
	if (*input)
		free(*input);
	*input = NULL;
}

// FUNCTION exit_parsing_status
// Frees parsing-related memory is freed and set to NULL:
// - the input string (original or modified)
// - the t_lex list containing typed tokens
// 
// If the minishell status is not currently 0, it is set to status...
// ... if it is not currently 0, the existing status is left unchanged.
//
// @return NULL pointer (cast to type as needed)
void	*exit_parsing_status(int stat, t_program *mshell, char **inp, t_lex **lex)
{
	if (*inp)
		free_null_input(inp);
	if (*lex)
		free_null_lex_list(lex);
	if (mshell->status == 0)
		mshell->status = stat;
	return (NULL);
}

// FUNCTION free_command_pipe
// Free the t_pipeline struct (which contains a t_command linked list and
// a int, num_cmds.
// @return NULL
t_pipeline	*free_command_pipe(t_pipeline *cmd_pipe)
{
	free_command_list(cmd_pipe->cmd);
	free(cmd_pipe);
	return (NULL);
}

