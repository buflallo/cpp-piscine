#include "Cat.hpp"

Cat::Cat() : AbsAnimal()
{
    std::cout << "Cat constructor" << std::endl;
    brain = new Brain();
    AbsAnimal::type = "Cat";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(Cat const & src) : AbsAnimal(src)
{
    std::cout << "Cat copy constructor" << std::endl;
    brain = new Brain();
    type = src.getType();
}

Cat & Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat assignation operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    brain = new Brain();
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
