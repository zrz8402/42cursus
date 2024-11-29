#include <iostream>
#include "PhoneBook.hpp"

int PhoneBook::getSize()
{
    return size;
}
void    PhoneBook::saveContact(const Contact& newContact)
{
    if (size < 8) {
        phonebook[size++] = newContact;
    } else {
        phonebook[oldestContact] = newContact;
        oldestContact = (oldestContact + 1) % 8;
    }
}

void    PhoneBook::displayContact(int i)
{
    std::cout << phonebook[i].getFirstName() << '\n';
}
