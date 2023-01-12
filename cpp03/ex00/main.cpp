#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap a("hamza");
    ClapTrap b("d3if");

    b.takeDamage(5);
    a.takeDamage(3);
    a.attack(b.getName());

    std::cout << a << std::endl;
    std::cout << b << std::endl;
}
