#include "AbsAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbsAnimal
{
    private:
    Brain *brain;
public:
    Dog();
    Dog(Dog const & src);
    ~Dog();
    Dog & operator=(Dog const & rhs);
    std::string getType() const;
    virtual void makeSound() const;
};
