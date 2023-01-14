#include "Base.hpp"

int main()
{
    Base *c;

    c = c->generate();
    Base &d = *c;
    d.identify(d);
    delete c;
}