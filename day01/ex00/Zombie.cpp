#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}