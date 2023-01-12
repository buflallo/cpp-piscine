#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const & src);
    ~WrongAnimal();
    WrongAnimal & operator=(WrongAnimal const & rhs);
    std::string getType() const;
    void makeSound() const;
};

#endif