#include "PhoneBook.hpp"

void PhoneBook::addContact(int *i)
{
    if (*i >= 0 && *i <= 7)
    {
        if (*i == 7)
            if (this->contacts[0].add() == 1)
                return ;
        if (this->contacts[*i].add() == 1)
            *i = *i + 1;
    }
}

void PhoneBook::showContacts(int index)
{
    int i = 0;
    std::string input;
    int err = 0;

    print_Spaces(50);
    std::cout << "|   index    |" << "First name |" << " Last name |" << " Nickname  |" << std::endl;
    while (i <= index)
    {
        if (!this->contacts[i].is_empty())
        {
            this->contacts[i].show(i);
            i++;
        }
        else if (i == 0)
            return ;
        else
            i++;
    }
    std::cout << "Enter index: ";
    std::getline(std::cin, input);
    if (input.length() == 0 || !std::isdigit(input[0]))
        err = 1;
    else
        i = std::atoi(input.c_str());
    // std::cin >> i;
    if (i >= 0 && i < index && !err)
    {
        this->searchContact(i);
    }
    else
        std::cout << "Wrong index" << std::endl;
}

void Good_Bye()
{
    print_Spaces(72);
    std::cout << "GOOD BYE !" << std::endl;
}

void PhoneBook::searchContact(int i)
{
    this->contacts[i].showOne();
    
}
