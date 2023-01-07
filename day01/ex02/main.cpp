#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "memory address of the string variable: " << &str << std::endl;
    std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "value of the string variable: " << str << std::endl;
    std::cout << "value of the string variable held by stringPTR: " << *stringPTR << std::endl;
    std::cout << "value of the string variable held by stringREF: " << stringREF << std::endl;
}