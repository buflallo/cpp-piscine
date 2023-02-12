#ifndef Form_HPP
#define Form_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(std::string const &, int gradeToSign, int gradeToExecute);
        Form(Form const & src);
        Form & operator=(Form const & rhs);
        ~Form();
        void beSigned(Bureaucrat const & obj);
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Grade too high";
        }
    };
    class Noinformation : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "No information";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Grade too low";
        }
    };

};

std::ostream &    operator<<(std::ostream & o, Form const & src);

#endif
