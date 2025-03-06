#include "minishell.h"

// t_lex		*lex_list;
// t_command	*cmd;
// t_env		*env_list;
// int			status;
// int			exit;

void    init(t_program *minishell, char **envp)
{
	ft_memset(minishell, 0, sizeof(t_program));
    // update_shlvl();
	minishell->envp = envp;
    init_env(minishell);
}

int	valid_arg(char *s)
{
	long long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13)|| *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s) || result > (LONG_MAX - (*s - '0')) / 10
			|| result < (LONG_MIN - 1 + (*s - '0')) / 10)
			return (0);
		result = result * 10 + sign * (*s - '0');
		s++;
	}
	return (1);
}

int	builtin_exit(t_command *cmd, t_program *minishell)
{
	if (cmd->args[1])
	{
		if (!valid_arg(cmd->args[1]))
		{
			ft_putendl_fd("exit", 2);
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(cmd->args[1], 2);	
			ft_putstr_fd(": numeric argument required\n", 2);
			free_lst(minishell->envlst);
			exit(2);
		}
		if (cmd->args[2])
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: too many argument  s\n", 2);
			return (1);	
		}
		minishell->status = ft_atoi(cmd->args[1]);
	}
	ft_putstr_fd("exit\n", 1);
	free_lst(minishell->envlst);
	exit(minishell->status);
}

void	process_in(pid_t pid, int *pipefd, char **av, char **envp, t_env *envlst)
{
	int	inf_fd;

	if (pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		// if (access(av[1], F_OK) == -1)
		// 	ft_error("No infile", 1, pipefd[1]);
		// inf_fd = open(av[1], O_RDONLY);
		// if (inf_fd < 0)
		// 	ft_error("Error opening input file", 1, pipefd[1]);
		// if (dup2(inf_fd, STDIN_FILENO) == -1)
		// 	ft_error("Duplicating infile fd failed", 1, pipefd[1]);
		// close(inf_fd);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execute(av, envlst, envp);
	}
}

int main(int ac, char **av, char **envp)
{
    t_program   minishell;

    (void) ac;
    (void) av;
    init(&minishell, envp);

	t_command cmd;

	int		pipefd[2];
	pid_t	pid1;

	char *arg3[] = {"ls", NULL};
	cmd.args = arg3;

	// if (pipe(pipefd) < 0)
	// 	ft_error("Failing creating pipe", 1, -1);
	// pid1 = fork();
	// process_in(pid1, pipefd, arg3, envp, minishell.envlst);


	// Testing env and unset

	// char *arg3[] = {"env", NULL};
	// cmd.args = arg3;
	// builtin_env(&cmd, &minishell);

	// char *arg1[] = {"unset", "PATH", NULL};
	// cmd.args = arg1;
	// builtin_unset(&cmd, &minishell);

	// char *arg2[] = {"env", NULL};
	// cmd.args = arg2;
	// builtin_env(&cmd, &minishell);


	// Testing exit

	// char *arg4[] = {"exit", "0", "9", NULL};
	// cmd.args = arg4;
	// builtin_exit(&cmd, &minishell);

	// char *arg4[] = {"exit", "259", NULL};
	// cmd.args = arg4;
	// builtin_exit(&cmd, &minishell);

	// char *arg4[] = {"exit", "9223372036854775807", NULL};
	// cmd.args = arg4;
	// builtin_exit(&cmd, &minishell);


	// Testing cd

	// printf("PWD: %s\n", get_var_value("PWD", minishell.envlst));
	// printf("OLD: %s\n\n", get_var_value("OLDPWD", minishell.envlst));

	// char *arg1[] = {"cd", NULL};
	// cmd.args = arg1;
	// builtin_cd(&cmd, &minishell);

	// char *arg3[] = {"env", NULL};
	// cmd.args = arg3;
	// builtin_env(&cmd, &minishell);

	// char *arg2[] = {"cd", "..", NULL};
	// cmd.args = arg2;
	// builtin_cd(&cmd, &minishell);

	// char *arg3[] = {"cd", "/home/ruzhang/eval", NULL};
	// cmd.args = arg3;
	// builtin_cd(&cmd, &minishell);

	// char *arg4[] = {"cd", "/home/ruzhang/eval", "/home", NULL};
	// cmd.args = arg4;
	// builtin_cd(&cmd, &minishell);

	// char *arg5[] = {"cd", "/ashf", NULL};
	// cmd.args = arg5;
	// builtin_cd(&cmd, &minishell);

	// printf("PWD: %s\n", get_var_value("PWD", minishell.envlst));
	// printf("OLD: %s\n", get_var_value("OLDPWD", minishell.envlst));


	// free_lst(minishell.envlst);
    // run();
    // cleanup();
	free_lst(minishell.envlst);
}