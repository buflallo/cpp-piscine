#include <iostream>
#include <string>
#include <exception>

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