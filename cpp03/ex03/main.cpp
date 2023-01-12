#include <iostream>
#include "DiamondTrap.hpp"

int main( void ) {
    DiamondTrap a("hamza");
    ClapTrap b("d3if");
    ScavTrap c("scav");
    FragTrap d("frag");

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    a.whoAmI();
    a.attack(b.getName());
    b.takeDamage(30);
    a.attack(c.getName());
    c.takeDamage(30);
    a.attack(d.getName());
    d.takeDamage(30);
    a.guardGate();
    a.highFivesGuys();
    d.highFivesGuys();
    c.guardGate();
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}
