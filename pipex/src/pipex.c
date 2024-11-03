/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:52 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/03 15:52:48 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parse_cmd(char *cmd)
{
	return (cmd);
}

void	first_child_process(char **av, int pipe[])
{
	int		input_fd;
	char	**args;
	char	*path;

	input_fd = open(av[1], O_RDONLY);
	if (input_fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	close(pipe[0]);
	dup2(input_fd, STDIN_FILENO);
	close(input_fd);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	args = ft_split(av[2], ' ');
	path = parse_cmd(args[0]);
	execve(path, args, __environ);
	perror("execve failed");
	exit(1);
}

void	last_child_process(char **av, int prev_pipe[], int ac)
{
	int		output_fd;
	char	**args;
	char	*path;

	close(prev_pipe[1]);
	output_fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (output_fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	dup2(prev_pipe[0], STDIN_FILENO);
	close(prev_pipe[0]);
	args = ft_split(av[3], ' ');
	path = parse_cmd(args[0]);
	execve(path, args, __environ);
	perror("execve failed");
	exit(1);
}

int	main(int ac, char **av)
{
	int		in_fd;
	int		out_fd;
	pid_t	pid;
	int		pipefd[2];

	if (ac < 5)
		return (0);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
		first_child_process(av, pipefd);
	pid = fork();
	if (pid == 0)
		last_child_process(av, pipefd, ac);
    close(pipefd[0]);
    close(pipefd[1]);
    for (int i = 0; i < 2; i++) {
        wait(NULL);
    }
}