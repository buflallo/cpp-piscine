#include <iostream>

class Zombie
{
private:
    std::string name;
    std::string type;
public:
    ~Zombie(void);
    void setName(std::string name);
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );