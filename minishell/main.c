#include "minishell.h"

// t_lex		*lex_list;
// t_command	*cmd;
// t_env		*env_list;
// int			status;
// int			exit;

void    init()
{
    init_env();
    update_shlvl();
}

int main(int ac, char **av, char **envp)
{
    t_program   minishell;

    (void) ac;
    (void) av;

    init();
    run();
    cleanup();
}