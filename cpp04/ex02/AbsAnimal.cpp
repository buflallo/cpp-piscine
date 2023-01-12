#include "AbsAnimal.hpp"

AbsAnimal::AbsAnimal()
{
    type = "AbsAnimal";
    std::cout << "AbsAnimal constructor" << std::endl;
}

AbsAnimal::~AbsAnimal()
{
    std::cout << "AbsAnimal destructor" << std::endl;
}

AbsAnimal::AbsAnimal(AbsAnimal const & src)
{
    std::cout << "AbsAnimal copy constructor" << std::endl;
    type = src.getType();
}

AbsAnimal & AbsAnimal::operator=(AbsAnimal const & rhs)
{
    std::cout << "AbsAnimal assignation operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    return *this;
}

std::string AbsAnimal::getType() const
{
    return this->type;
}

void AbsAnimal::makeSound() const
{
    std::cout << "AbsAnimal sound" << std::endl;
}
