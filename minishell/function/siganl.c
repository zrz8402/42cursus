#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define PROMPT "minishell> "

/* Signal handler for SIGINT (Ctrl+C) in the main shell */
void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0); // Clear the current input line
	rl_on_new_line();       // Move to a new prompt line
	rl_redisplay();         // Redisplay the prompt
}

/* Setup signal handlers */
void	setup_signals(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

/* Reset signals before executing a child process */
void	reset_signals(void)
{
	struct sigaction sa;

	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

/* Execute a command using fork and execve */
void	execute_command(char *cmd)
{
	pid_t	pid;
	int		status;
	char	*args[] = {cmd, NULL};

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return;
	}
	if (pid == 0) // Child process
	{
		reset_signals();
		if (execvp(cmd, args) == -1)
		{
			perror("execvp");
			exit(127);
		}
	}
	else // Parent process
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			int sig = WTERMSIG(status);
			if (sig == SIGINT)
				write(1, "\n", 1);
			else if (sig == SIGQUIT)
				write(1, "Quit (core dumped)\n", 19);
		}
	}
}

int	main(void)
{
	char	*cmd;

	setup_signals();
	while (1)
	{
		cmd = readline(PROMPT);
		if (!cmd) // Handle Ctrl+D (EOF)
		{
			write(1, "exit\n", 5);
			break;
		}
		if (*cmd)
		{
			add_history(cmd); // Store command in history
			execute_command(cmd);
		}
		free(cmd);
	}
	return (0);
}