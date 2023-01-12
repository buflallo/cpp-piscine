#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // AbsAnimal *AbsAnimals[4];

    // for (int i = 0; i < 4; i++)
    // {
    //     if (i % 2 == 0)
    //         AbsAnimals[i] = new Dog();
    //     else
    //         AbsAnimals[i] = new Cat();
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     AbsAnimals[i]->makeSound();
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     delete AbsAnimals[i];
    // }

    const AbsAnimal* j = new Dog();
    const AbsAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;
}