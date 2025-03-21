/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:53:39 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/20 13:24:54 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	g_signal = sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	heredoc_handler(int sig)
{
	write(1, "\n", 1);
	g_signal = sig;
	close(STDIN_FILENO);
}

void	exec_handler(int sig)
{
	g_signal = sig;
}
