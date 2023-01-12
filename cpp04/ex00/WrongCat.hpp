#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(WrongCat const & src);
    ~WrongCat();
    WrongCat & operator=(WrongCat const & rhs);
    std::string getType() const;
    // virtual void makeSound() const;
};
