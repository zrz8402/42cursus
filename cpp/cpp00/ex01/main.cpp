#include <iostream>
#include "PhoneBook.hpp"

void    addContact(PhoneBook& phoneBook)
{
    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
    } while (firstName.empty());
    newContact.setFirstName(firstName);
    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
    } while (lastName.empty());
    newContact.setLastName(lastName);
    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
    } while (nickname.empty());
    newContact.setNickname(nickname);
    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
    } while (phoneNumber.empty());
    newContact.setPhoneNumber(phoneNumber);
    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkestSecret);
    } while (darkestSecret.empty());
    newContact.setDarkestSecret(darkestSecret);
    phoneBook.saveContact(newContact);
}

bool    validEntry(std::string entry, int limit)
{
    if (entry.length() == 1){
        if (entry[0] >= '0' && entry[0] <= (limit + '0'))
            return true;
    }
    return false;
}

void    searchContact(PhoneBook& phoneBook)
{
    std::string index;
    int         maxEntry = phoneBook.getSize() - 1;

    do {
        std::cout << "Enter the entry index(0 - " << maxEntry << "): ";
        std::getline(std::cin, index);
    } while (!validEntry(index, maxEntry));
    phoneBook.displayContact(index[0] - '0');
}

int main(void)
{
    std::string cmd;
    PhoneBook phoneBook;

    std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
    std::getline(std::cin, cmd);
    while (cmd != "EXIT") {
        if (cmd == "ADD") {
            addContact(phoneBook);
        } else if (cmd == "SEARCH") {
            searchContact(phoneBook);
        } else {
            std::cout << "Not a valid command\n";
            break;
        }
        std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);
        
    }
    return (0);
}