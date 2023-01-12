#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal copy constructor" << std::endl;
    type = src.getType();
}

Animal & Animal::operator=(Animal const & rhs)
{
    std::cout << "Animal assignation operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
