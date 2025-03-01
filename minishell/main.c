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

int main(int ac, char **av, char **envp)
{
    t_program   minishell;

    (void) ac;
    (void) av;

    init(&minishell, envp);
	// print_lst(minishell.envlst);
	// free_lst(minishell.envlst);

	t_command cmd;

	char *arg3[] = {"env", "PATH", NULL};
	cmd.args = arg3;
	builtin_env(&cmd, &minishell);

	char *arg1[] = {"unset", "PATH", NULL};
	cmd.args = arg1;
	builtin_unset(&cmd, &minishell);

	char *arg2[] = {"env", "PATH", NULL};
	cmd.args = arg2;
	builtin_env(&cmd, &minishell);
	free_lst(minishell.envlst);


    // run();
    // cleanup();
}