/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:33:04 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 19:20:17 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_pipex
{
	int		is_heredoc;
	char	*inf;
	char	*outf;
	char	*delimiter;
	int		num_cmds;
	int		prev_pipe[2];
	int		cur_pipe[2];
	pid_t	*pids;
	int		start;
	char	*cmd;
}	t_pipex;

void	no_outfile(char *file);
void	ft_error(char *message, int code, t_pipex *pipex);
void	f_error(char *message, int code, t_pipex *p, int fd);
void	free_arr(char **s);

void	execute(char *cmd, char **envp, t_pipex *p);

void	process_in(char *av, char **envp, t_pipex *p);
void	process_out(char *av, char **envp, t_pipex *p);
void	general_process(char *av, char **envp, t_pipex *p);

#endif