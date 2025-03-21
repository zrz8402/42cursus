/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:00:50 by kmartin           #+#    #+#             */
/*   Updated: 2025/03/20 13:36:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t g_signal = 0;

char	*lex_type_to_string(enum e_ltype type);
void	print_command_list(t_command *cmd_list);

// Run test_case function to test parsing test cases;
// 
// input is freed inside parse_pipeline
int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_program	minishell;
	t_pipeline	*cmd_pipe;

	init(&minishell, envp);
	input = readline("$ ");
	cmd_pipe = parse_pipeline(&input, &minishell);
	if (!cmd_pipe)
	{
		printf("\nCommand pipe returned as NULL.\n\n");
	}
	else
	{
		print_command_list(cmd_pipe->cmd);
		free_command_pipe(cmd_pipe);
		cmd_pipe = NULL;
	}
	printf("Minishell status: %i\n\n", minishell.status);
	free_program(&minishell);
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

// FUNCTION print_command_list
// Helper function to print a visualization of a command list
void	print_command_list(t_command *cmd_list)
{
	int		cmd;
	int		i;
	t_redir	*redir;
	char	*str_type;

	if (!cmd_list)
		printf("cmd_list NULL\n\n");
	cmd = 1;
	while (cmd_list)
	{
		printf("\nCOMMAND %i:\n", cmd++);
		printf("\nArgs:\n");
		i = 0;
		while (cmd_list->args && cmd_list->args[i])
		{
			printf("arg %i: %s\n", i + 1, cmd_list->args[i]);
			i++;
		}
		printf("\nRedirections:\n");
		i = 1;
		redir = cmd_list->redirections;
		while (redir)
		{
			str_type = lex_type_to_string(redir->type);
			printf("redir %i: %s (%s)\n", i, redir->file, str_type);
			free(str_type);
			i++;
			redir = redir->next;
		}
		printf("\n");
		cmd_list = cmd_list->next;
	}
}
