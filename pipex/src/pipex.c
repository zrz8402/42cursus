/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:52 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/09 20:11:03 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

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

void	ft_error(char *message, int status)
{
	perror(message);
	exit(status);
}

char	*parse_cmd(char **args)
{
	char	*cmd;
	char	*full;
	char	**paths;
	int		i = 0;

	if (!args || !*args)
		ft_error("command not found", 127);
	cmd = args[0];
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*environ)
	{
		if (ft_strncmp(*environ, "PATH=", 5) == 0)
		{
			paths = ft_split(*environ + 5, ':');
			break ;
		}
		environ++;
	}
	if (!*environ)
		ft_error("command not found", 127);
	while (paths[i])
	{
		full = ft_strjoin(paths[i], ft_strjoin("/", cmd));
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	free_arr(args);
	ft_error("command not found", 127);
	return (NULL);
}

void	first_child_process(char **av, int pipefd[2])
{
	int		input_fd;
	char	**args;
	char	*path;

	input_fd = open(*av, O_RDONLY);
	if (input_fd < 0)
		ft_error("Error opening file", 1);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		ft_error("Duplicating fd failed", 1);
	close(input_fd);
	
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating pipefd failed", 1);
	close(pipefd[1]);
	args = ft_split(av[1], ' ');
	path = parse_cmd(args);
	execve(path, args, environ);
	free(path);
	free_arr(args);
	ft_error("execve failed", 127);
}

void	last_child_process(char **av, int pipefd[2], int output_fd)
{
	char	**args;
	char	*path;

	if (output_fd < 0)
		ft_error("Error opening file", 1);
	close(pipefd[1]);
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		ft_error("Duplicating fd failed", 1);
	close(output_fd);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_error("Duplicating pipefd failed", 1);
	close(pipefd[0]);
	args = ft_split(*(--av), ' ');
	path = parse_cmd(args);
	execve(path, args, environ);
	printf("something went wrong");
	free_arr(args);
	ft_error("execve failed", 127);
}

void	printArr(char **arr)
{
	for (int i = 0; arr[i]; i++)
		printf("%s\n", arr[i]);
}

void	general_child_process(char **av, int prev_pipe[2], int cur_pipe[2])
{
	char	**args;
	char	*path;

	close(prev_pipe[1]);
	if (dup2(prev_pipe[0], STDIN_FILENO) == -1)
		ft_error("Duplicating fd failed", 1);
	close(prev_pipe[0]);
	close(cur_pipe[0]);
	if (dup2(cur_pipe[1], STDOUT_FILENO) == -1)
		ft_error("Duplicating fd failed", 1);
	close(cur_pipe[1]);
	args = ft_split(*(++av), ' ');
	path = parse_cmd(args);
	printf("%s\n", path);
	execve(path, args, environ);
	free_arr(args);
	ft_error("execve failed", 127);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		prev_pipe[2];
	int		cur_pipe[2];
	int		status;


	if (ac < 5)
		return (1);
	int output_fd;
	if (access(av[ac - 1], F_OK) == -1)
		output_fd = open(av[ac - 1], O_WRONLY | O_CREAT , 0644);
	else
		output_fd = open(av[ac - 1], O_WRONLY | O_TRUNC);
	for (int i = 0; i < ac - 3; i++)
	{
		if (i != 0 || i != ac - 4)
			ft_memcpy(prev_pipe, cur_pipe, sizeof(int) * 2);
		if (i != ac - 4)
		{
			if (pipe(cur_pipe) == -1)
				ft_error("Failing creating pipe", 1);
		}
		pid = fork();
		if (pid < 0)
			ft_error("Fork failed", 1);
        if (pid == 0)
        {
            if (i == 0)
                first_child_process(++av, cur_pipe);
            else if (i == ac - 4)
                last_child_process(&av[ac - 1], cur_pipe, output_fd);
            else
				general_child_process(++av + i, prev_pipe, cur_pipe);
        }
		else
		{
			if (i != 0)
			{
				close(prev_pipe[0]);
				close(prev_pipe[1]);
			}
		}
    }
	while (wait(&status) > 0)
        ;
	//printf("%d\n", WEXITSTATUS(status));
	return (WEXITSTATUS(status));
}
