#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor" << std::endl;
    Animal::type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
    std::cout << "Dog copy constructor" << std::endl;
    type = src.getType();
}

Dog & Dog::operator=(Dog const & rhs)
{
    std::cout << "Dog assignation operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    return *this;
}

std::string Dog::getType() const
{
    return this->type;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}
