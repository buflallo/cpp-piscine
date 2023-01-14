#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;


class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);

        Bureaucrat & operator=(Bureaucrat const & rhs);

        std::string getName(void) const;
        int getGrade(void) const;
        

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(Form &form);
        void executeForm(Form const & form);


    private:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too low";
                }
        };
        class Noinformation : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "No information";
                }
        };
        std::string const name;
        int grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif