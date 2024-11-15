/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:44:02 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 16:17:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_process(int prev_pipe[2], int cur_pipe[2], int i, int n)
{
	if (i != 0)
	{
		close(prev_pipe[0]);
		close(prev_pipe[1]);
	}
	if (i != n)
	{
		prev_pipe[0] = cur_pipe[0];
		prev_pipe[1] = cur_pipe[1];
	}
}

void	init_p(t_pipex *p, char **av, int ac)
{
	p->is_heredoc = 0;
	if (!ft_strncmp(av[1], "here_doc", 9))
		p->is_heredoc = 1;
	p->inf = av[1];
	p->outf = av[ac - 1];
	p->num_cmds = ac - 3;
	p->start = 2;
	if (p->is_heredoc)
	{
		p->delimiter = av[2];
		p->num_cmds = ac -4;
		p->start = 3;
	}
	p->prev_pipe[0] = -1;
	p->prev_pipe[1] = -1;
	p->cur_pipe[0] = -1;
	p->cur_pipe[1] = -1;
	p->pids = malloc(p->num_cmds * sizeof(pid_t));
	if (!p->pids)
		ft_error("Malloc failure", 1, p);
	p->cmd = NULL;
}

void	process(t_pipex *p, char **av, char **envp)
{
	int	i;

	i = -1;
	while (++i < p->num_cmds)
	{
		if (i < p->num_cmds - 1)
		{
			if (pipe(p->cur_pipe) == -1)
				ft_error("Failing creating pipe", 1, p);
		}
		p->pids[i] = fork();
		if (p->pids[i] < 0)
			ft_error("Fork failed", 1, p);
        if (p->pids[i] == 0)
        {
            if (i == 0)
				process_in(*av, envp, p);
            else if (i == p->num_cmds - 1)
            	process_out(*av, envp, p);
            else
				general_process(*av, envp, p);
        }
		parent_process(p->prev_pipe, p->cur_pipe, i, p->num_cmds - 1);
		av++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	p;
	int		status;

	if (ac < 5 || (!ft_strncmp(av[1], "here_doc", 9) && ac < 6))
		ft_error("Bad arguments", 1, NULL);
	no_outfile(av[ac - 1]);
	init_p(&p, av, ac);
	av += p.start;
	process(&p, av, envp);
	for (int i = 0; i < p.num_cmds; i++)
		waitpid(p.pids[i], &status, 0);
	free(p.pids);
	return (WEXITSTATUS(status));
}
