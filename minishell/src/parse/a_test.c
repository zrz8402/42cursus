/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:00:50 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/14 12:23:04 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*lex_type_to_string(enum e_ltype type);
void	print_command_pipe(t_command *cmd_pipe);

// Run test_case function to test parsing test cases;
int	main()
{
	char		*input;
	t_pipeline	*cmd_pipe;

	input = readline("$ ");

	cmd_pipe = parse_pipeline(&input);
	free(input);

	print_command_pipe(cmd_pipe->cmd);

	free_command_pipe(cmd_pipe);

	return (0);
}

// FUNCTION lex_type_to_string
// Translate the lex type to a string representation.
//
// NB: free returned string in calling function.
char	*lex_type_to_string(enum e_ltype type)
{
	char	*str_type;

	if (type == COMMAND)
		str_type = ft_strdup("COMMAND");
	if (type == ARGUMENT)
		str_type = ft_strdup("ARGUMENT");
	if (type == PIPE)
		str_type = ft_strdup("PIPE");
	if (type == RED_OUT)
		str_type = ft_strdup("RED_OUT");
	if (type == RED_IN)
		str_type = ft_strdup("RED_IN");
	if (type == APPEND)
		str_type = ft_strdup("APPEND");
	if (type == HEREDOC)
		str_type = ft_strdup("HEREDOC");
	if (type == NO_TYPE)
		str_type = ft_strdup("NO_TYPE");

	return (str_type);
}

// FUNCTION print_command_pipe
// Helper function to print a visualization of a command pipe
void	print_command_pipe(t_command *cmd_pipe)
{
	int		cmd;
	int		i;
	t_redir	*redir;
	char	*str_type;

	if (!cmd_pipe)
		printf("cmd_pipe NULL\n\n");
	cmd = 1;
	while (cmd_pipe)
	{
		printf("\nCOMMAND %i:\n", cmd++);
		printf("\nArgs:\n");
		i = 0;
		while (cmd_pipe->args && cmd_pipe->args[i])
		{
			printf("arg %i: %s\n", i + 1, cmd_pipe->args[i]);
			i++;
		}
		printf("\nRedirections:\n");
		i = 1;
		redir = cmd_pipe->redirections;
		while (redir)
		{
			str_type = lex_type_to_string(redir->type);
			printf("redir %i: %s (%s)\n", i, redir->file, str_type);
			free(str_type);
			i++;
			redir = redir->next;
		}
		printf("\n");
		cmd_pipe = cmd_pipe->next;
	}
}
