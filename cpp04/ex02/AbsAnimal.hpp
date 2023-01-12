#ifndef AbsAnimal_HPP
# define AbsAnimal_HPP

#include <string>
#include <iostream>

class AbsAnimal
{
protected:
    std::string type;
public:
    AbsAnimal();
    AbsAnimal(AbsAnimal const & src);
    virtual ~AbsAnimal();
    AbsAnimal & operator=(AbsAnimal const & rhs);
    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif