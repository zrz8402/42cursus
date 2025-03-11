#include "minishell.h"

void	setup_child_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
void	sigint_handler(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	setup_exec_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_prompt_signal(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **envp)
{
	t_program	minishell = {NULL, envp, NULL, 0};
	t_pipeline	*pipeline;
	char		*input;

	init_env(&minishell);
	while (1)
	{
		setup_prompt_signal();
		input = readline("minishell$ ");
		if (!input)
		{
			free_lst(minishell.envlst);
			printf("exit\n");
			break;
		}
		if (*input)
			add_history(input);
		if (*input)
		{
			setup_exec_signal();
			pipeline = parse_pipeline(input);
			process_pipeline(pipeline, &minishell);
			free(input);
		}
	}
	return (0);
}