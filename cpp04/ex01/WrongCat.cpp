#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat constructor" << std::endl;
    WrongAnimal::type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
    std::cout << "WrongCat copy constructor" << std::endl;
    type = src.getType();
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
    std::cout << "WrongCat assignation operator" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    return *this;
}

std::string WrongCat::getType() const
{
    return this->type;
}

