#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string Name;
        int         HitPoints;
        int         EnergyPoints;
        int         AttackDamage;
    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & src);
        ~ClapTrap(void);
        ClapTrap & operator=(ClapTrap const & rhs);
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const;
        int getAttackDamage(void) const;
};

std::ostream & operator<<(std::ostream & o, ClapTrap const & rhs);