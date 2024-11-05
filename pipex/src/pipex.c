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
extern char **environ;

char	*parse_cmd(char *cmd)
{
	return (cmd);
}

void	ft_error(char *message)
{
	perror(message);
	exit(1);
}

void	free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	first_child_process(char **av, int pipefd[2])
{
	int		input_fd;
	char	**args;
	char	*path;

	input_fd = open(*av, O_RDONLY);
	if (input_fd < 0)
		ft_error("Error opening file");
	close(pipefd[0]);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		ft_error("Duplicating fd failed");
	close(input_fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating fd failed");
	close(pipefd[1]);
	args = ft_split(*(++av), ' ');
	path = parse_cmd(args[0]);
	execve(path, args, environ);
	free_arr(args);
	ft_error("execve failed");
}

void	last_child_process(char **av, int pipefd[2], int ac)
{
	int		output_fd;
	char	**args;
	char	*path;

	close(pipefd[1]);
	output_fd = open(*av, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (output_fd < 0)
		ft_error("Error opening file");
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		ft_error("Duplicating fd failed");
	close(output_fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_error("Duplicating fd failed");
	close(pipefd[0]);
	args = ft_split(*(--av), ' ');
	path = parse_cmd(args[0]);
	execve(path, args, environ);
	free_arr(args);
	ft_error("execve failed");
}

void	general_child_process(char **av, int prev_pipe[2], int cur_pipe[2], int ac)
{
	char	**args;
	char	*path;

	close(prev_pipe[1]);
	if (dup2(prev_pipe[0], STDIN_FILENO) == -1)
		ft_error("Duplicating fd failed");
	close(prev_pipe[0]);
	close(cur_pipe[0]);
	if (dup2(cur_pipe[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating fd failed");
	close(cur_pipe[1]);
	args = ft_split(*(++av), ' ');
	path = parse_cmd(args[0]);
	execve(path, args, environ);
	free_arr(args);
	ft_error("execve failed");
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		prev_pipe[2];
	int		cur_pipe[2];

	if (ac < 5)
		return (1);
	for (int i = 0; i < ac - 3; i++)
	{
		if (i != 0)
		{
			prev_pipe[0] = cur_pipe[0];
			prev_pipe[1] = cur_pipe[1];
		}
		if (i != ac - 4)
		{
			if (pipe(cur_pipe) == -1)
				ft_error("Failing creating pipe");
		}
		pid = fork();
		if (pid < 0)
			ft_error("Fork failed");
        if (pid == 0)
        {
            if (i == 0)
                first_child_process(++av, cur_pipe);
            else if (i == ac - 4)
                last_child_process(&av[ac - 1], cur_pipe, ac);
            else
				general_child_process(++av + i, prev_pipe, cur_pipe, ac);
        }
		if (i != 0)
		{
			close(prev_pipe[0]);
			close(prev_pipe[1]);
		}
    }
    for (int i = 0; i < ac - 3; i++) {
        wait(NULL);
    }
}
