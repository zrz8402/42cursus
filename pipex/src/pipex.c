#include "pipex.h"

int main(int ac, char **av, char **envp)
{
    int pipefd[2];
    pid_t   pid1;
    pid_t   pid2;

    if (ac != 5)
        return (0);
    if (access(av[ac - 1]))
}