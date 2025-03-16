/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:52:34 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/12 19:40:21 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// FUNCTION parse_pipeline
// Function to return command pipeline linked list to be used in final progam.
//
// NB: Pass the address of the char* string from readline: the tokenize function
// modifies/replaces the provided string during expansion of variables; the 
// modifed/replaced string must then be freed by the program that calls this
// function.
//
// @param char** string received from readline
//
// @return command pipeline with arguments and redirections
t_pipeline	*parse_pipeline(char **input)  // WILL NEED TO GET MSHELL ENV VARIABLES FOR EXPANSION
{
	t_lex		*input_lex;
	t_command	*cmd_list;
	t_pipeline	*cmd_pipe;

	input_lex = tokenize(input);

	cmd_list = get_commands(input_lex);

	cmd_pipe = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!cmd_pipe)
		printf("ERROR in parse_pipeline: EXIT GRACEFULLY!!!\n");		

	cmd_pipe->cmd = cmd_list;
	cmd_pipe->num_cmds = count_commands(input_lex);

	free_lex_list(input_lex);

	return (cmd_pipe);
}

// FUNCTION free_command_pipe
// Free the t_pipeline struct (which contains a t_command linked list and
// a int, num_cmds.
void	free_command_pipe(t_pipeline *cmd_pipe)
{
	free_command_list(cmd_pipe->cmd);
	free(cmd_pipe);
}
