#include "Base.hpp"

Base *generate(void)
{
    int Rand;
    srand(time(NULL));
    Rand = rand() % 3;
    if(Rand == 0)
        return dynamic_cast<Base *> (new A());
    else if(Rand == 1)
        return dynamic_cast<Base *> (new B());
    else
        return dynamic_cast<Base *> (new C());
}

void identify(Base *p)
{
    A *ptrA;
    B *ptrB;
    C *ptrC;

    ptrA = dynamic_cast<A*>(p);
    ptrB = dynamic_cast<B*>(p);
    ptrC = dynamic_cast<C*>(p);
    if (ptrA != NULL)
        std::cout << ptrA << " is A" << std::endl;
    if (ptrB != NULL)
        std::cout << ptrB << " is B" << std::endl;
    if (ptrC != NULL)
        std::cout << ptrC << " is C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &ptrA = dynamic_cast<A&>(p);
        std::cout << &ptrA << " is A" << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        try
        {
            B &ptrB = dynamic_cast<B&>(p);
            std::cout << &ptrB << " is B" << std::endl;
        }
        catch(const std::bad_cast& e)
        {
            try
            {
                C &ptrC = dynamic_cast<C&>(p);
                std::cout << &ptrC << " is C" << std::endl;
            }
            catch(const std::bad_cast& e)
            {
                std::cout << &p << " is not an object" << std::endl;
            }
        }
    }
}
