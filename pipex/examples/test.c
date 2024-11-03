#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    int pipefd[2];
    pid_t pid;
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    char *keyword = "-l"; // Change this to your desired search term

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork first child for grep
    if ((pid = fork()) == 0) {
        close(pipefd[0]); // Close read end of the pipe
        int input_fd = open(input_file, O_RDONLY);
        if (input_fd == -1) {
            perror("open input file");
            exit(EXIT_FAILURE);
        }

        // Redirect stdin from input file
        dup2(input_fd, STDIN_FILENO);
        // Redirect stdout to the write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        
        close(pipefd[1]); // Close write end
        close(input_fd); // Close input file descriptor

        char *args[] = {"ls", keyword, NULL};
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

	printf("pid: %d\n", pid);

    // Fork second child for writing to file
    if ((pid = fork()) == 0) {
        close(pipefd[1]); // Close write end of the pipe

        // Open output file
        int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (output_fd == -1) {
            perror("open output file");
            exit(EXIT_FAILURE);
        }

        // Redirect stdout to the output file
        dup2(output_fd, STDOUT_FILENO);
        
        close(output_fd); // Close output file descriptor

        // Redirect stdin to read end of the pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]); // Close read end of the pipe

        char *args[] = {"cat", NULL}; // Use cat to write the output to the file
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
	printf("pid: %d\n", pid);
    // Parent process
    close(pipefd[0]); // Close read end of the pipe
    close(pipefd[1]); // Close write end of the pipe

    // Wait for both children to finish
    for (int i = 0; i < 2; i++) {
        wait(NULL);
    }

    printf("Filtered results written to '%s'.\n", output_file);
    return 0;
}
