#include "Base.hpp"

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

A::A()
{
    std::cout << "A constructor called" << std::endl;
}

A::~A()
{
    std::cout << "A destructor called" << std::endl;
}


B::~B()
{
    std::cout << "B destructor called" << std::endl;
};

B::B()
{
    std::cout << "B constructor called" << std::endl;
}



C::~C()
{
    std::cout << "C destructor called" << std::endl;
}

C::C()
{
    std::cout << "C constructor called" << std::endl;
}

Base *Base::generate(void)
{
    int Rand;
    srand((unsigned) time(NULL));
    Rand = rand() % 3;
    if(Rand == 0)
        return reinterpret_cast<Base *> (new A());
    if(Rand == 1)
        return reinterpret_cast<Base *> (new B());
    if(Rand == 2)
        return reinterpret_cast<Base *> (new C());
    return NULL;
}

void Base::identify(Base *p)
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

void Base::identify(Base &p)
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
