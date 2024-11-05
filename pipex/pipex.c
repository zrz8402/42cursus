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

void	first_child_process(char **av, int pipefd[2])
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
	close(pipefd[0]);
	dup2(input_fd, STDIN_FILENO);
	close(input_fd);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	args = ft_split(av[2], ' ');
	path = parse_cmd(args[0]);
	execve(path, args, __environ);
	perror("execve failed");
	exit(1);
}

void	last_child_process(char **av, int pipefd[2], int ac)
{
	int		output_fd;
	char	**args;
	char	*path;

	close(pipefd[1]);
	output_fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (output_fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	args = ft_split(av[ac - 2], ' ');
	path = parse_cmd(args[0]);
	execve(path, args, __environ);
	perror("execve failed");
	exit(1);
}

void	generate_child_process(char **av, int prev_pipe[2], int cur_pipe[2], int ac)
{
	return ;
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		prev_pipe[2];
	int		cur_pipe[2];

	if (ac < 5)
		return (0);
	for (int i = 0; i < ac - 3; i++)
	{
		if (i != 0)
		{
			prev_pipe[0] = cur_pipe[0];
			prev_pipe[1] = cur_pipe[1];
		}
		if (i != ac - 4)
			pipe(cur_pipe);
		pid = fork();
        if (pid == 0)
        {
            if (i == 0)
                first_child_process(av, cur_pipe);
            else if (i == ac - 4)
                first_child_process(av, cur_pipe);
            else
                generate_child_process(av, prev_pipe, cur_pipe, ac);
        }
    }
    close(prev_pipe[0]);
    close(prev_pipe[1]);
    close(cur_pipe[0]);
    close(cur_pipe[1]);
    for (int i = 0; i < ac - 3; i++) {
        wait(NULL);
    }
}