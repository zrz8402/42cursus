/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:53:39 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/27 14:18:34 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
rl_replace_line("", 0);
	Clear the current line in the Readline buffer
rl_on_new_line();
	Move to a new line, to ensure that the prompt starts on the next line
rl_redisplay();
	Re-render the prompt after clearing the line
*/
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
