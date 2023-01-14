#include "Form.hpp"


Form::~Form()
{
}

Form::Form(Form const & src) :  name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat const & obj)
{
    if (obj.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    else
        isSigned = true;
}

std::string Form::getName(void) const
{
    return this->name;
}

bool Form::getIsSigned(void) const
{
    return this->isSigned;
}

int Form::getGradeToSign(void) const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute(void) const
{
    return this->gradeToExecute;
}


std::ostream &    operator<<(std::ostream & o, Form const & src)
{
    o << src.getName() << ", form grade to sign " ;
    o << src.getGradeToSign() << ", form grade to execute ";
    o << src.getGradeToExecute() << std::endl;
    o << "status : Form is " << (src.getIsSigned() ? "Well Signed" : "Not signed") << std::endl;
    return o;
}
