#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Open a file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Redirect standard output (fd 1) to the file
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("Error redirecting stdout");
        close(fd);
        return 1;
    }

    // Now all printf statements will go to output.txt
    printf("This will be written to output.txt\n");

    // Close the file descriptor
    close(fd);

    return 0;
}
