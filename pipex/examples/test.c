#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is exiting.\n", getpid());
        exit(42); // Exit with a status of 42
    } else {
        // Parent process
        int status;
        pid_t child_pid = waitpid(pid, &status, 0); // Wait for the child to finish

        if (child_pid == -1) {
            perror("waitpid failed");
            return EXIT_FAILURE;
        }

        // Check if the child exited normally
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status); // Get the exit status
            printf("Child process (PID: %d) exited normally with status: %d\n", child_pid, exit_status);
        } else {
            printf("Child process (PID: %d) did not exit normally.\n", child_pid);
        }
    }

    return EXIT_SUCCESS;
}
