/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:10:32 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/11 18:44:30 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}


void	test_handler(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n", 1);
}

void	test_handler1(int sig)
{
	(void) sig;
	write(1, "Quit (core dumped)\n", 19);
}

void	test_handler2(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n", 1);
}

void	setup_child_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	// struct sigaction	sa;

	// sa.sa_handler = SIG_DFL;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA_RESTART;

	// sigaction(SIGINT, &sa, NULL);
	// sigaction(SIGQUIT, &sa, NULL);

}

void	setup_exec_signal(void)
{
	// struct sigaction	sa;

	// sa.sa_handler = SIG_IGN;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA_RESTART;

	// sigaction(SIGINT, &sa, NULL);
	// sigaction(SIGQUIT, &sa, NULL);

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_prompt_signal(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);

	// struct sigaction	sa;

	// sa.sa_handler = sigint_handler;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA_RESTART;

	// sigaction(SIGINT, &sa, NULL);
	// sa.sa_handler = SIG_IGN;
	// sigaction(SIGQUIT, &sa, NULL);
}

// void	setup_heredoc_signal(void)
// {
// 	struct sigaction	sa;

// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = 0;

// 	sa.sa_handler = handle_heredoc_signal;
// 	sigaction(SIGINT, &sa, NULL);
// 	sa.sa_handler = SIG_IGN;
// 	sigaction(SIGQUIT, &sa, NULL);
// }
