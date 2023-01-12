#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    ClapTrap a("hamza");
    ClapTrap b("d3if");
    ScavTrap c("scav");
    FragTrap d("frag");

    std::cout << a << std::endl;
    std::cout << c << std::endl;
}
