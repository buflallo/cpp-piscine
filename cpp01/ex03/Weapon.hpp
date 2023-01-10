#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        ~Weapon();
        Weapon(std::string weapon);
        std::string const& getType();
        void    setType(std::string Type);
};

#endif