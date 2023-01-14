#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat b("first",6);
        Bureaucrat c("second",7);
        Form form("kill", 4, 7);
        std::cout << b << std::endl;
        std::cout << form;
        b.signForm(form);
        std::cout << form;
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}