#include "Zombie.hpp"
#define N 100

int main()
{
    Zombie *x;

    x = zombieHorde(N, "haha");
    delete [] x;
}