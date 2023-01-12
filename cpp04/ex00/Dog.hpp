#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(Dog const & src);
    ~Dog();
    Dog & operator=(Dog const & rhs);
    std::string getType() const;
    virtual void makeSound() const;
};
