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


int main() {
    // Example pipeline: "echo hello | cat"
    t_pipeline pipeline;
    
    // Command 1: "echo hello"
    t_command cmd1;
    char *args1[] = {"echo", "hello", NULL};
    t_redir redir1;
    redir1.redirection = NULL;  // No redirection for this command
    cmd1.args = args1;
    cmd1.redirections = &redir1;
    cmd1.next = NULL;

    // Command 2: "cat"
    t_command cmd2;
    char *args2[] = {"cat", NULL};
    t_redir redir2;
    redir2.redirection = NULL;  // No redirection for this command
    cmd2.args = args2;
    cmd2.redirections = &redir2;
    cmd2.next = NULL;

    // Connect the commands in the pipeline
    cmd1.next = &cmd2;
    pipeline.cmd = &cmd1;
    pipeline.num_cmds = 2;

    // Process the pipeline
    process_pipeline(&pipeline);

    return 0;
}