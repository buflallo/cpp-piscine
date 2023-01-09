#include "Zombie.hpp"

int main()
{
    Zombie *x;

    x = zombieHorde(10, "haha");
    delete [] x;
}