#include "Zombie.hpp"

int main()
{
    Zombie *x;
    x = newZombie("haha");
    x->announce();
    delete x;
    randomChump("lala");
}