#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    int total = 2;
    const Animal *animals[total];

    int i = 0;
    while (i < total)
    {
        if (total / 2 <= i)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        i++;
    }
    i = 0;
    Dog* dog = const_cast<Dog*>(dynamic_cast<const Dog*>(animals[1]));
    if (dog)
    {
        std::cout << "\e[0;31m";
        dog->getBrain(0);
        dog->setBrain(" is to take a  shower", 0);
        dog->getBrain(0);
        std::cout << "\e[m";
    }
    Cat* cat = const_cast<Cat*>(dynamic_cast<const Cat*>(animals[0]));
    std::cout << "\e[0;31m";
    cat->getBrain(0);
    cat->setBrain(" is to go for a walk", 0);
    cat->getBrain(0);
    std::cout << "\e[m";
    while (i < total)
        delete animals[i++];
    //-------------
    Dog dog1;
    Dog dog2(dog1);
    Dog dog3;
    dog3 = dog2;
    Dog dog4 = dog3;
    Dog ttemp;
    {
        Dog dog1 = ttemp;
    }
    // //-------------
}
