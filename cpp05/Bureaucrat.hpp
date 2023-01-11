#include <iostream>

class Bureaucrat : public std::exception
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);

        Bureaucrat & operator=(Bureaucrat const & rhs);

        std::string getName(void) const;
        int getGrade(void) const;
        std::string GradeTooHighException(void) const;
        std::string GradeTooLowException(void) const;
        

        void incrementGrade(void);
        void decrementGrade(void);

    private:

        std::string const _name;
        int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);