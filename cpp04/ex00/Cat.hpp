#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(Cat const & src);
    ~Cat();
    Cat & operator=(Cat const & rhs);
    std::string getType() const;
    virtual void makeSound() const;
};
