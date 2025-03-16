/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/14 14:55:25 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_append(char *file, t_program *minishell)
{
	int	outf_fd;

	if (is_dir(file))
		return (ft_error(file, IS_DIR, minishell, 1), 1);
	outf_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outf_fd < 0)
		return (ft_error(file, NO_PERMISSION, minishell, 1), 1);
	dup2(outf_fd, STDOUT_FILENO);
	close(outf_fd);
	return (0);
}
