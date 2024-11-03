#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening output file");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("Error redirecting stdout");
        close(fd);
        return 1;
    }

    char *args[] = {"ls", "-l", NULL};
    char *env[] = {"PATH=/bin:/usr/bin", NULL};

    if (execve(args[0], args, env) < 0) {
        perror("Error executing ls");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
