#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void disable_echo() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);  // Get current settings
    newt = oldt;
    newt.c_lflag &= ~ECHO;           // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    printf("Enter password: ");
    char password[100];
    fgets(password, sizeof(password), stdin);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore settings
    printf("\nYou entered: %s", password);
}

int main() {
    disable_echo();
    return 0;
}
