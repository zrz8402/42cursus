/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:03:36 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/16 15:07:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (*input)
		{
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
				minishell->status = 0;
				process_pipeline(pipeline, minishell);
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
