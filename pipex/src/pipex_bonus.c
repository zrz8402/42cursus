/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:44:02 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/15 11:05:04 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_process(char **av, int pipefd[2], char **envp)
{
	int		inf_fd;
	char	**args;
	char	*path;

	close(pipefd[0]);
	inf_fd = open(*av, O_RDONLY);
	if (inf_fd < 0)
	{
		close(pipefd[1]);
		ft_error("Error opening input file", 1);
	}
	if (dup2(inf_fd, STDIN_FILENO) == -1)
	{
		close(pipefd[1]);
		ft_error("Duplicating infile fd failed", 1);
	}
	close(inf_fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating pipefd failed", 1);
	close(pipefd[1]);
	execute(av[1], envp);
}

void	last_child_process(char **av, int pipefd[2], int ac, char **envp)
{
	int outf_fd;

	close(pipefd[1]);
	outf_fd = open(*av, O_WRONLY | O_TRUNC);
	if (outf_fd < 0)
	{
		close(pipefd[0]);
		ft_error("Error opening output file", 1);
	}
	if (dup2(outf_fd, STDOUT_FILENO) == -1)
	{
		close(pipefd[0]);
		ft_error("Duplicating outfile fd failed", 1);
	}
	close(outf_fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_error("Duplicating pipefd failed", 1);
	close(pipefd[0]);
	execute(*(--av), envp);
}

void	general_child_process(char **av, int prev_pipe[2], int cur_pipe[2], char **envp)
{
	close(prev_pipe[1]);
	if (dup2(prev_pipe[0], STDIN_FILENO) == -1)
		ft_error("Duplicating fd failed", 1);
	close(prev_pipe[0]);
	close(cur_pipe[0]);
	if (dup2(cur_pipe[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating fd failed", 1);
	close(cur_pipe[1]);
	execute(*(++av), envp);
}

void	init_pipex(t_pipex *pipex, char **av)
{
	pipex->is_heredoc = 0;
	if (!ft_strncmp(av[1], "here_doc", 9))
		pipex->is_heredoc = 1;
}

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

int	main(int ac, char **av, char **envp)
{
	int		prev_pipe[2];
	int		cur_pipe[2];
	int		*pid;
	int		status;

	if (ac < 5 || (!ft_strncmp(av[1], "here_doc", 9) && ac < 6))
		ft_error("Bad arguments", 1);
	no_outfile(av[ac - 1]);
	pid = malloc((ac - 3) * sizeof(int));
	int i = 0;
	while (i < ac - 3)
	{
		if (i != ac - 4)
		{
			if (pipe(cur_pipe) == -1)
				ft_error("Failing creating pipe", 1);	
		}
		pid[i] = fork();
		if (pid[i] < 0)
			ft_error("Fork failed", 1);
        if (pid[i] == 0)
        {
            if (i == 0)
                first_child_process(++av, cur_pipe, envp);
            else if (i == ac - 4)
                last_child_process(&av[ac - 1], prev_pipe, ac, envp);
            else
				general_child_process(++av + i, prev_pipe, cur_pipe, envp);
        }
		parent_process(prev_pipe, cur_pipe, i, ac - 4);
		i++;
	}

	for (int i = 0; i < ac - 3; i++)
	{
		waitpid(pid[i], &status, 0);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (WEXITSTATUS(status));
}
