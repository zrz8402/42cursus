#include "pipex.h"

void	no_outfile(char **av, int ac)
{
	int output_fd;

	if (access(av[ac - 1], F_OK) == -1)
	{
		output_fd = open(av[ac - 1], O_WRONLY | O_CREAT , 0644);
		if (output_fd < 0)
		{
			perror("Failing creating output file");
			exit(1);
		}
		close(output_fd);
	}
}

void	wait_close(int *status, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
    {
		wait(status);
		printf("%d %d\n", i, WEXITSTATUS(*status));
	}
	// close(STDIN_FILENO);
	// close(STDOUT_FILENO);
	// close(STDERR_FILENO);
}
