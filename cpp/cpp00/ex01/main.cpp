#include <iostream>

void    saveContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
    } while (firstName.empty());
    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
    } while (lastName.empty());
    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
    } while (nickname.empty());
    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
    } while (phoneNumber.empty());
    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkestSecret);
    } while (darkestSecret.empty());
}

int main(void)
{
    std::string cmd;

    std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
    std::getline(std::cin, cmd);
    while (cmd != "EXIT") {
        if (cmd == "ADD") {
            saveContact();
        } else if (cmd == "SEARCH") {
            std::cout << "to be added\n";
        } else {
            std::cout << "Not a valid command\n";
            break;
        }
        std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);
    }
    return (0);
}