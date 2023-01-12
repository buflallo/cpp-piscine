#include "PhoneBook.hpp"


int main()
{
    PhoneBook pb;
    int index = 0;
    std::string str;

    print_Spaces(54);
    std::cout << "WELCOME TO OLD PHONEBOOKS DAYS (ENJOY): " << std::endl;
    while(1 && std::cin)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, str);
        if (str == "ADD")
            pb.addContact(&index);
        else if (str == "SEARCH")
            pb.showContacts(index);
        else if (str == "EXIT")
        {
            Good_Bye();
            break;
        }
    }
    // pb.searchContact(0);
    return (0);
}