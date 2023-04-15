#include <iostream>

typedef struct Data{
    int i;
}Data;

class Serializer {
    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer const& obj);
        Serializer & operator=(Serializer const & rhs);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};