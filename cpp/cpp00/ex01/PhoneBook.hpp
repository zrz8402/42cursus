#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact     phonebook[8];
        int         size = 0;
        int         oldestContact = 0;

    public:
        int     getSize();
        void    saveContact(const Contact& newContact);
        void    displayContact(int i);
};

#endif