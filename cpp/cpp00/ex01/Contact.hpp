#include <string>

class Contact {
    private:
        std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    public:
        void   setFirstName(const std::string& newFirstName);
        void   setLastName(const std::string& newLastName);
        void   setNickname(const std::string& newNickname);
        void   setPhoneNumber(const std::string& newPhoneNumber);
        void   setDarkestSecret(const std::string& newDarkestSecret);

        std::string   getFirstName() const;
        std::string   getLastName() const;
        std::string   getNickname() const;
        std::string   getPhoneNumber() const;
        std::string   getDarkestSecret() const;
};