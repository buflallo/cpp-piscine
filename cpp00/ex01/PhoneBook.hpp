#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
    public:
        void addContact(int *i);
        void showContacts(int index);
        void searchContact(int i);
};

void Good_Bye();