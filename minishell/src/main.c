/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:03:36 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/17 14:48:44 by ruzhang          ###   ########.fr       */
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
			if (ft_strcmp(input, "echo $?") == 0)
			{
				char *status = ft_itoa(minishell->status);
				ft_putendl_fd(status, STDOUT_FILENO);
				free(status);
			}
			else
			{
				pipeline = parse_pipeline(&input);
				free(input);
				g_signal = 0;
				setup_exec_signal();
				minishell->status = 0;
				process_pipeline(pipeline, minishell);
				if (g_signal == SIGINT)
					write(1, "\n", 1);
			}
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_program	minishell;

	init(&minishell, envp);
	run_shell(&minishell);
	return (0);
}
