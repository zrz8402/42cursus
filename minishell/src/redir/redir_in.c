/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:58 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/14 14:40:23 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_in(char *file, t_program *minishell)
{
	int	inf_fd;

	if (access(file, F_OK) == -1)
		return (ft_error(file, FILE_NOT_FOUND, minishell, 1), 1);
	inf_fd = open(file, O_RDONLY);
	if (inf_fd < 0)
		return (ft_error(file, NO_PERMISSION, minishell, 1), 1);
	dup2(inf_fd, STDIN_FILENO);
	close(inf_fd);
	return (0);
}
