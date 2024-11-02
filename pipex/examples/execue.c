#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Open output file
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening output file");
        return 1;
    }

    // Redirect standard output to the file
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("Error redirecting stdout");
        close(fd);
        return 1;
    }

    // Prepare arguments for execve()
    char *args[] = {"/bin/ls", "-l", NULL};
    char *env[] = {}; // No special environment variables

    // Execute the ls command
    if (execve(args[0], args, env) < 0) {
        perror("Error executing ls");
        close(fd);
        return 1;
    }

    // Close the file descriptor (this line will not be reached if execve is successful)
    close(fd);

    return 0;
}
