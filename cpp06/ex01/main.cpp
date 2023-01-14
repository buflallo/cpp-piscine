#include <iostream>

typedef struct Data{
    int i;
}Data;

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data d;

    uintptr_t p;

    d.i = 5;
    
    std::cout << "SERIALIIIIZE : " << &d << std::endl;
    std::cout << d.i << std::endl;
    
    p = serialize(&d);
    
    std::cout << "DESERIALIIIZE : " << p << std::endl;
    
    Data *l = deserialize(p);
    std::cout << "l address : " << l << std::endl;
    std::cout << "d address : " << &d << std::endl;

}