/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:33:04 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 11:08:31 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct  s_pipex
{
	int	inf;
	int	outf;
	int	is_heredoc;
	int	prev_pipe[2];
	int	cur_pipe[2];
}	t_pipex;


void	no_outfile(char *file);
void	ft_error(char *message, int code);
void	free_arr(char **s);

void	execute(char *cmd, char **envp);
#endif