#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->Name = rhs.Name;
    this->HitPoints = rhs.HitPoints;
    this->EnergyPoints = rhs.EnergyPoints;
    this->AttackDamage = rhs.AttackDamage;
    return *this;
}

void ClapTrap::attack(std::string const & target)
{
    if (HitPoints == 0 || EnergyPoints <= 0)
        return;
    std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints == 0 || EnergyPoints <= 0)
        return;
    std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
    if (HitPoints < 0)
        HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints == 0 || EnergyPoints <= 0)
        return;
    std::cout << "ClapTrap " << this->Name << " is repaired for " << amount << " points!" << std::endl;
    HitPoints += amount;
    EnergyPoints--;
    if (HitPoints > 10)
        HitPoints = 10;
}

std::string ClapTrap::getName(void) const
{
    return Name;
}

int ClapTrap::getHitPoints(void) const
{
    return HitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return EnergyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
    return AttackDamage;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &rhs)
{
    o << rhs.getName() << " Energy pts: " << rhs.getEnergyPoints() << " Hit pts: " << rhs.getHitPoints() << " Attack dmg: " << rhs.getAttackDamage();
    return o;
}
