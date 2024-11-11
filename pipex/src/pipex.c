/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:52 by ruzhang           #+#    #+#             */
/*   Updated: 2024/11/10 16:47:03 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	execute(char *cmd, char **envp)
{
	char	**paths;
	char	*full;
	char	**args;
	int		i = 0;

	args = ft_split(cmd, ' ');
	if (!args || !*args)
		//*args = "";
		ft_error("Empty command", 127);}
	if (access(args[0], X_OK) == 0)
	{
		execve(args[0], args, envp);
	}
	if (access(args[0], F_OK) == 0)
		ft_error("Command permission", 126);
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			paths = ft_split(*envp + 5, ':');
			break ;
		}
		envp++;
	}
	while (paths[i])
	{
		full = ft_strjoin(paths[i], ft_strjoin("/", args[0]));
		if (access(full, X_OK) == 0)
			execve(full, args, envp);
		free(full);
		i++;
	}
}

void	first_child_process(char **av, int pipefd[2], char **envp)
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
	execute(av[1], envp);
}

void	last_child_process(char **av, int pipefd[2], int ac, char **envp)
{
	int output_fd;

	output_fd = open(*av, O_WRONLY | O_TRUNC);
	if (output_fd < 0)
		ft_error("Error opening file", 1);
	close(pipefd[1]);
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		ft_error("Duplicating output fd failed", 1);
	close(output_fd);
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

void	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		ft_error("Failing creating pipe", 1);	
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

void process(char **av, char **envp, int ac)
{
	pid_t	pid;
	int		prev_pipe[2];
	int		cur_pipe[2];
	int		i;

	i = 0;
	while (i < ac - 3)
	{
		if (i != ac - 4)
			create_pipe(cur_pipe);
		pid = fork();
		if (pid < 0)
			ft_error("Fork failed", 1);
        if (pid == 0)
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
}

int	main(int ac, char **av, char **envp)
{
	int		status;

	if (ac < 5)
		return (0);
	no_outfile(av, ac);
	process(av, envp, ac);
	wait_close(&status, ac - 3);
	return (WEXITSTATUS(status));
}
