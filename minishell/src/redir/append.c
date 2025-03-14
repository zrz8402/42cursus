/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:43 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/14 13:47:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_append(char *file)
{
	int	outf_fd;

	outf_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outf_fd < 0)
	{
		ft_putendl_fd(" Permission denied", 2);
		return (1);
	}
	dup2(outf_fd, STDOUT_FILENO);
	close(outf_fd);
	return (0);
}
