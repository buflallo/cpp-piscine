#include "Dog.hpp"

Dog::Dog() : AbsAnimal()
{
    std::cout << "Dog constructor" << std::endl;
    brain = new Brain();
    AbsAnimal::type = "Dog";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(Dog const & src) : AbsAnimal(src)
{
    std::cout << "Dog copy constructor" << std::endl;
    brain = new Brain();
    type = src.getType();
}

Dog & Dog::operator=(Dog const & rhs)
{
    std::cout << "Dog assignation operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    brain = new Brain();
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
