/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:58 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/14 13:47:47 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_in(char *file)
{
	int	inf_fd;

	if (access(file, F_OK) == -1)
	{
		ft_putendl_fd(" No such file or directory", 2);
		return (1);
	}
	inf_fd = open(file, O_RDONLY);
	if (inf_fd < 0)
	{
		ft_putendl_fd(" Permission denied", 2);
		return (1);
	}
	dup2(inf_fd, STDIN_FILENO);
	close(inf_fd);
	return (0);
}
