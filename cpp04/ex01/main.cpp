#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal *Animals[4];

    // for (int i = 0; i < 4; i++)
    // {
    //     if (i % 2 == 0)
    //         Animals[i] = new Dog();
    //     else
    //         Animals[i] = new Cat();
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     Animals[i]->makeSound();
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     delete Animals[i];
    // }

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;
}