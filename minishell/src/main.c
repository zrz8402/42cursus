/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:03:36 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/27 13:43:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

void	check_sig(t_program *minishell)
{
	if (g_signal == SIGINT)
		minishell->status = g_signal + 128;
	g_signal = 0;
}

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
		check_sig(minishell);
		setup_exec_signal();
		if (*input)
		{
			add_history(input);
			pipeline = parse_pipeline(&input, minishell);
			if (pipeline)
				process_pipeline(pipeline, minishell);
		}
		else
			free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_program	minishell;

	(void) argv;
	if (argc > 1)
	{
		ft_putendl_fd("Too many args", STDERR_FILENO);
		return (0);
	}
	init(&minishell, envp);
	run_shell(&minishell);
	return (0);
}
