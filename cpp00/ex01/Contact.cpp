#include "Contact.hpp"

int Contact::is_empty()
{
    if (this->firstName.length() == 0 && this->lastName.length() == 0 && this->nickname.length() == 0 && this->phoneNumber.length() == 0 && this->darkestSecret.length() == 0)
        return (1);
    return (0);
}

int Contact::add()
{
    std::cout << "First name: ";
    std::getline(std::cin, this->firstName);
    if (!std::cin)
        return (0);
    std::cout << "Last name: ";
    std::getline(std::cin, this->lastName);
    if (!std::cin)
        return (0);
    std::cout << "Nickname: ";
    std::getline(std::cin, this->nickname);
    if (!std::cin)
        return (0);
    std::cout << "Phone number: ";
    std::getline(std::cin, this->phoneNumber);
    if (!std::cin)
        return (0);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, this->darkestSecret);
    if (!std::cin)
        return (0);
    if (this->is_empty())
        return (0);
    return (1);
}

void print_Spaces(int n)
{
    int i = 0;

    while (i < n)
    {
        std::cout << " ";
        i++;
    }
}

static void print_Value(std::string str)
{
    std::string tmp;
    
    tmp = str;
    tmp.resize(9);
    std::cout << "|" << tmp;
    if(str.length() >= 10)
        std::cout << ". ";
    else
        print_Spaces(11 - str.length());
}

void Contact::show(int index)
{
    std::string tmp;

    print_Spaces(50);
    std::cout << "|" << index;
    print_Spaces(11);
    print_Value(this->firstName);
    print_Value(this->lastName);
    print_Value(this->nickname);
    std::cout << "|";
    std::cout << std::endl;
    std::cout << std::endl;
}

void Contact::showOne()
{
    std::string tmp;

    std::cout << "firstName: " << this->firstName << std::endl;
    std::cout << "lastName: " << this->lastName << std::endl;
    std::cout << "nickname: " << this->nickname << std::endl;
    std::cout << "phoneNumber: " << this->phoneNumber << std::endl;
    std::cout << "darkestSecret: " << this->darkestSecret << std::endl;
    // print_Spaces(11);
    // print_Value(this->firstName);
    // print_Value(this->lastName);
    // print_Value(this->nickname);
    std::cout << std::endl;
    std::cout << std::endl;
}