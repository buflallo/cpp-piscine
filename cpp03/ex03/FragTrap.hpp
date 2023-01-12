#include "ClapTrap.hpp"

class FragTrap :  virtual public ClapTrap
{
private:
    /* data */
public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);
};
