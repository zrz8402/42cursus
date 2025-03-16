/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:28 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/14 14:41:18 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_heredoc(int heredoc_fd, t_program *minishell)
{
	dup2(heredoc_fd, STDIN_FILENO);
	close(heredoc_fd);
	return (0);
}
