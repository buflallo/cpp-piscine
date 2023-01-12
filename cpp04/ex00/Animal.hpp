#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal const & src);
    ~Animal();
    Animal & operator=(Animal const & rhs);
    std::string getType() const;
    virtual void makeSound() const;
};

#endif