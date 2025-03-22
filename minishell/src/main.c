/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:03:36 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/22 12:54:10 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t g_signal = 0;

void	run_shell(t_program *minishell)
{
	char		*input;
	t_pipeline	*pipeline;

	while (1)
	{
		setup_prompt_signal();
		input = readline("minishell$ ");
		if (!input)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			free_program(minishell);
			break ;
		}
		if (g_signal == SIGINT)
		{
			minishell->status = g_signal + 128;
			g_signal = 0;
		}
		if (*input)
		{
			setup_exec_signal();
			add_history(input);
			pipeline = parse_pipeline(&input, minishell);
			if (input)
				free(input); // redundant - input should be freed and set to NULL inside parse_pipeline
			g_signal = 0;
			setup_exec_signal();
			minishell->status = 0;
			if (pipeline)
				process_pipeline(pipeline, minishell);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_program	minishell;

	(void) argc;
	(void) argv;
	init(&minishell, envp);
	run_shell(&minishell);
	return (0);
}
