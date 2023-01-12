#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor" << std::endl;
    Animal::type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
    std::cout << "Cat copy constructor" << std::endl;
    type = src.getType();
}

Cat & Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat assignation operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    return *this;
}

std::string Cat::getType() const
{
    return this->type;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}
