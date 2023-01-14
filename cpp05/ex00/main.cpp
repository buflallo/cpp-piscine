#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat b("first",6);
        Bureaucrat c("second",4);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}