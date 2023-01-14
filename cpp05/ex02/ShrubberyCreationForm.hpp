
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>
#include <iostream>

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
    private:
        std::string _target;
    public :
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
        void execute(Bureaucrat const & executor) const;
};

#endif