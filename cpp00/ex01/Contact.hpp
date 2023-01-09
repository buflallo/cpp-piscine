#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        int    add();
        int    is_empty();
        void    show(int index);
        void showOne();
};

void print_Spaces(int n);