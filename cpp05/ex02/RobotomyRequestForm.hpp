
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;
    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        void execute(Bureaucrat const & executor) const;
};

#endif