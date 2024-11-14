/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:49:28 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/14 13:41:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_in(pid_t pid, int *pipefd, char **av, char **envp)
{
	int	inf_fd;

	if (pid < 0)
		ft_error("Fork failure", 1);
	if (pid == 0)
	{
		close(pipefd[0]);
		inf_fd = open(av[1], O_RDONLY);
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
		execute(av[2], envp);
	}
}

void	process_out(pid_t pid, int *pipefd, char **av, char **envp)
{
	int	outf_fd;

	if (pid < 0)
		ft_error("Fork failure", 1);
	if (pid == 0)
	{
		close(pipefd[1]);
		outf_fd = open(av[4], O_WRONLY | O_TRUNC);
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
		execute(av[3], envp);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (ac != 5)
		ft_error("Bad arguments", 0);
	no_outfile(av[ac - 1]);
	if (pipe(pipefd) < 0)
		ft_error("Failing creating pipe", 1);
	pid1 = fork();
	process_in(pid1, pipefd, av, envp);
	pid2 = fork();
	process_out(pid2, pipefd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (WEXITSTATUS(status));
}
