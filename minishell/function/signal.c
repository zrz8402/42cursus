// #include "minishell.h"

// void	sigint_handler(int sig)
// {
// 	(void) sig;
// 	write(STDOUT_FILENO, "\n", 1);
// 	rl_replace_line("", 0);
// 	rl_on_new_line();
// 	rl_redisplay();
// }

// void	setup_child_signal(void)
// {
// 	signal(SIGINT, SIG_DFL);
// 	signal(SIGQUIT, SIG_DFL);
// }
// void	setup_exec_signal(void)
// {
// 	signal(SIGINT, SIG_IGN);
// 	signal(SIGQUIT, SIG_IGN);
// }

// void	setup_prompt_signal(void)
// {
// 	signal(SIGINT, sigint_handler);
// 	signal(SIGQUIT, SIG_IGN);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	t_program	minishell = {NULL, envp, NULL, 0};
// 	t_pipeline	*pipeline;
// 	char		*input;

// 	init_env(&minishell);
// 	while (1)
// 	{
// 		setup_prompt_signal();
// 		input = readline("minishell$ ");
// 		if (!input)
// 		{
// 			free_lst(minishell.envlst);
// 			printf("exit\n");
// 			break;
// 		}
// 		if (*input)
// 			add_history(input);
// 		if (*input)
// 		{
// 			setup_exec_signal();
// 			pipeline = parse_pipeline(input);
// 			process_pipeline(pipeline, &minishell);
// 			free(input);
// 		}
// 	}
// 	return (0);
// }

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

void parent_handler(int sig) {
	write(STDOUT_FILENO, "Parent: SIGINT received\n", 24);
}

void parent_handler2(int sig) {
	write(STDOUT_FILENO, "Parent: SIGQUIT received\n", 25);
}

void child_handler(int sig) {
	write(STDOUT_FILENO, "Child: SIGINT received\n", 23);
}

void child_handler2(int sig) {
	write(STDOUT_FILENO, "Child: SIGQUIT received\n", 24);
}

void handle_eof(int sig) {
	write(STDOUT_FILENO, "EOF (Ctrl+D) received, exiting...\n", 33);
	exit(0);
}

void setup_child_signal(void) {
	signal(SIGINT, child_handler);
	signal(SIGQUIT, child_handler2);
}

void setup_parent_signal(void) {
	signal(SIGINT, parent_handler);
	signal(SIGQUIT, parent_handler2);
}

int main() {
	char buffer[128];
	int	status;
	pid_t pid = fork();
		
	if (pid == 0)
	{
		setup_child_signal();

		while (1)
		{
			write(STDOUT_FILENO, "Child: Waiting for input... (Ctrl+D to exit)\n", 46);
			if (read(STDIN_FILENO, buffer, sizeof(buffer)) == 0)
				handle_eof(SIGTERM);
			sleep(2);
		}
	}
	else if (pid > 0)
	{
		setup_parent_signal();

		while (1)
		{
			write(STDOUT_FILENO, "Parent: Waiting for input... (Ctrl+D to exit)\n", 46);
			if (read(STDIN_FILENO, buffer, sizeof(buffer)) == 0)
				break ;
				// handle_eof(SIGTERM);
			sleep(4);
		}
	}
	else
	{
		perror("fork");
		return 1;
	}
	wait(&status);
	return 0;
}

