#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

// Function to handle here_doc, which reads input until the delimiter is encountered
void here_doc(char *delimiter, int pipe_fd[2]) {
    char buffer[BUFFER_SIZE];
    int len;

    // Close the write end of the pipe in the current process
    close(pipe_fd[0]);

    // Read input until the delimiter is encountered
    while (1) {
        printf("heredoc> ");  // Optional: Add a prompt for user input
        if (!fgets(buffer, BUFFER_SIZE, stdin)) {
            break;  // Break on EOF (Ctrl+D)
        }

        // If the input matches the delimiter, stop reading
        len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';  // Remove newline character
        }

        if (strcmp(buffer, delimiter) == 0) {
            break;  // Exit when the delimiter is encountered
        }

        // Write the buffer to the pipe
        write(pipe_fd[1], buffer, strlen(buffer));
    }

    // Close the write end of the pipe when done
    close(pipe_fd[1]);
}

// Sample child process that reads from a pipe
void child_process(int *fd, char **envp, char *cmd) {
    close(fd[1]);  // Close the write end of the pipe in the child
    dup2(fd[0], STDIN_FILENO);  // Redirect STDIN to read from the pipe

    // Execute the command
    execlp(cmd, cmd, (char *)NULL);  // Assuming you want to run the cmd with execlp
    perror("execlp failed");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **envp) {
    int fd[2];
    pid_t pid;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <here_doc_delimiter> <cmd>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // In child process: execute the command
        child_process(fd, envp, argv[2]);
    } else {
        // In parent process: handle the here_doc
        here_doc(argv[1], fd);

        // Wait for the child process to finish
        wait(NULL);
    }

    return 0;
}
