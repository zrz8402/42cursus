#include <stdio.h>	
#include <unistd.h>
#include <fcntl.h>

// Just wanna see how we rediect
int	main(void)
{
	char	*redirect[8] = {"<", "in1", "<", "in2", ">", "out1", ">>", "out2"};
	char	*cmds[3] = {"/bin/cat", NULL};

	if (access(redirect[1], F_OK) == -1)
		return (perror("NO INFILE"), 1);
	int	in1 = open(redirect[1], O_RDONLY);
	if (in1 < 0)
		return (perror("Error opening file"), 1);
	dup2(in1, STDIN_FILENO) == -1;
	close(in1);

	int	in2 = open(redirect[3], O_RDONLY);
	if (in2 < 0)
		return (perror("Error opening file"), 1);
	dup2(in2, STDIN_FILENO) == -1;
	close(in2);

	int	out1 = open(redirect[5], O_WRONLY | O_TRUNC);
	if (out1 < 0)
		return (perror("Error opening file"), 1);
	dup2(out1, STDOUT_FILENO) == -1;
	close(out1);

	int	out2 = open(redirect[7], O_WRONLY | O_APPEND);
	if (out2 < 0)
		return (perror("Error opening file"), 1);
	dup2(out2, STDOUT_FILENO) == -1;
	close(out2);
	execve(cmds[0], cmds, __environ);
}
