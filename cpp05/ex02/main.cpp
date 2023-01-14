#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
   try 
   {
        Bureaucrat B("aristo",45);
        ShrubberyCreationForm S("vio");
        RobotomyRequestForm R("Robot");
        PresidentialPardonForm P("Document");
        B.signForm(S);
        B.executeForm(S);
        B.signForm(R);
        B.executeForm(R);
        B.signForm(P);
        B.executeForm(P);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}