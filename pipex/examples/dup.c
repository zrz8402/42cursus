#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor
    int new_fd = dup(fd);
    if (new_fd < 0) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    // Now you can use new_fd to write to the same file
    write(new_fd, "Hello, World!\n", 14);

    // Close the original and duplicated file descriptors
    close(fd);
    close(new_fd);

    return 0;
}
