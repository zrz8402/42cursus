#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <wait.h>

#define MAX_ARGS 10

// Structure to represent a simple command
typedef struct s_command {
    char *args[MAX_ARGS];  // Command arguments
    char *input_redir;     // Input redirection (e.g., file name for '<')
    char *output_redir;    // Output redirection (e.g., file name for '>')
} t_command;

// Function to handle SIGINT signal (Ctrl+C)
void sigint_handler(int sig) {
    (void)sig;
    write(STDOUT_FILENO, "\n$ ", 3);  // Print prompt again after SIGINT
}

// Function to process redirections
int process_redirections(t_command *cmd) {
    // Handle input redirection
    if (cmd->input_redir) {
        int in_fd = open(cmd->input_redir, O_RDONLY);
        if (in_fd == -1) {
            perror("Error opening input file");
            return 1;  // Error opening input file
        }
        dup2(in_fd, STDIN_FILENO);  // Redirect stdin to the input file
        close(in_fd);
    }

    // Handle output redirection
    if (cmd->output_redir) {
        int out_fd = open(cmd->output_redir, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (out_fd == -1) {
            perror("Error opening output file");
            return 1;  // Error opening output file
        }
        dup2(out_fd, STDOUT_FILENO);  // Redirect stdout to the output file
        close(out_fd);
    }

    return 0;  // Success
}

// Function to execute built-in commands like "echo" and "exit"
void exec_builtin(t_command *cmd) {
    if (strcmp(cmd->args[0], "echo") == 0) {
        // Echo command
        for (int i = 1; cmd->args[i] != NULL; i++) {
            printf("%s ", cmd->args[i]);
        }
        printf("\n");
    } else if (strcmp(cmd->args[0], "exit") == 0) {
        // Exit command
        exit(0);
    } else {
        // Unknown command (not a built-in)
        write(STDOUT_FILENO, "Unknown command\n", 16);
    }
}

// Function to execute external commands
void exec_external(t_command *cmd) {
    pid_t pid = fork();
    if (pid == 0) {  // Child process
        // Process any redirections first
        if (process_redirections(cmd) != 0) {
            exit(1);  // Exit if redirection failed
        }

        // Execute external command using execvp
        if (execvp(cmd->args[0], cmd->args) == -1) {
            perror("Command execution failed");
            exit(1);  // Exit if execvp fails
        }
    } else if (pid > 0) {  // Parent process
        wait(NULL);  // Wait for the child process to finish
    } else {
        perror("fork failed");
        exit(1);
    }
}

// Function to execute a command (including redirection and built-ins)
void execute_command(t_command *cmd) {
    // Process redirections
    if (process_redirections(cmd) != 0) {
        return;  // If redirection fails, don't proceed
    }

    // Check if it's a built-in command
    if (cmd->args[0] != NULL) {
        if (strcmp(cmd->args[0], "echo") == 0 || strcmp(cmd->args[0], "exit") == 0) {
            exec_builtin(cmd);
        } else {
            // Execute external command (not a built-in)
            exec_external(cmd);
        }
    }
}

int main() {
    // Set up the signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, sigint_handler);

    // Main shell loop
    while (1) {
        // Print prompt
        write(STDOUT_FILENO, "$ ", 2);

        // Get command input from the user
        char input[256];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  // Exit on EOF (Ctrl+D)
        }

        // Remove the newline character from the input string
        input[strcspn(input, "\n")] = 0;

        // Parse the input into a command (simplified here)
        // In a real shell, you would tokenize and handle different cases
        t_command cmd = { .input_redir = NULL, .output_redir = "out"};
        cmd.args[0] = strtok(input, " ");  // Get the first word (the command)
        int i = 1;
        while (cmd.args[i - 1] != NULL && i < MAX_ARGS - 1) {
            cmd.args[i] = strtok(NULL, " ");  // Get subsequent arguments
            i++;
        }

        // Handle redirections (simple handling of "<" and ">")
        if (strchr(input, '<')) {
            cmd.input_redir = strtok(NULL, " ");  // Take the next word as input redirection
        }
        if (strchr(input, '>')) {
            cmd.output_redir = strtok(NULL, " ");  // Take the next word as output redirection
        }

        // Execute the command
        execute_command(&cmd);
    }

    return 0;
}
