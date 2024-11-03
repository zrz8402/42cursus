/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:52 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/03 15:51:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipes(int **pipefd, int n)
{
	while (n--)
		free(pipefd[n]);
	free(pipefd);
}

void	ft_error(char *message)
{
	perror(message);
	exit(1);
}

int	**init_pipes(int n) // num_of_pipes = num_of_cmds - 1 = ac - 4
{
	int	i;
	int	**pipefd;

	pipefd = malloc(n * sizeof(int *));
	if (!pipefd)
		ft_error("Malloc Failure");
	i = -1;
	while (++i < n)
	{
		pipefd[i] = malloc(2 * sizeof(int));
		if (!pipefd[i])
		{
			free_pipes(pipefd, i);
			ft_error("Malloc Failure");
		}
		if (pipe(pipefd[i]) == -1)
		{
			free_pipes(pipefd, i);
			ft_error("Failing creating pipes");
		}
	}
	return (pipefd);
}

// int	main(int ac, char **av)
// {
// 	int	**pipefd;

// 	if (ac < 5)
// 		return (0);
// 	pipefd = init_pipes(ac - 4);
// 	free_pipes(pipefd, ac - 4);
// }

void	last_child_process(int **pipefd, int n, int output_fd, char **av, char **env)
{
	int	cpid;
	char	**args;

	cpid = fork();
	if (cpid == -1)
	{
		free_pipes(pipefd, n);
		ft_error("Fork failure");
	}
	if (cpid == 0)
	{
		close(pipefd[n - 1][1]);
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
		dup2(pipefd[n - 1][0], STDIN_FILENO);
		close(pipefd[0][0]);
		args = ft_split(av[3], ' ');
		execve(args[0], args, env);
		ft_error("execve failed");
	}
}

void	first_child_process(int **pipefd, int n, int input_fd, char **av, char **env)
{
	int	cpid;
	char	**args;

	cpid = fork();
	if (cpid == -1)
	{
		free_pipes(pipefd, n);
		ft_error("Fork failure");
	}
	if (cpid == 0)
	{
		close(pipefd[0][0]);
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
		dup2(pipefd[0][1], STDOUT_FILENO);
		close(pipefd[0][1]);
		args = ft_split(av[2], ' ');
		execve(args[0], args, env);
		ft_error("execve failed");
	}
}

int	main(int ac, char **av)
{
	int		in_fd;
	int		out_fd;
	pid_t	pid;
	int		pipefd[2];

	if (ac < 5)
		return (0);

	in_fd = open(av[1], O_RDONLY);
	if (in_fd < 0)
		perror("Error opening file");
	printf("%s %d\n", av[1], in_fd);

	out_fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (out_fd < 0)
		perror("Error opening file");
	pid = fork();
	// if (pid == 0)
	// 	first_child_process(pipefd, ac - 4, in_fd, av, env);
	// pid = fork();
	// if (pid == 0)
	// 	last_child_process(pipefd, ac - 4, out_fd, av, env);
    // close(pipefd[0][0]);
    // close(pipefd[0][1]);
    // close(pipefd[1][0]);
    // close(pipefd[1][1]);

    // Wait for both children to finish
    // for (int i = 0; i < 2; i++) {
    //     wait(NULL);
    // }
}