#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal* meta = new Animal();
    Animal* j = new Dog();
    Animal* i = new Cat();
    WrongAnimal* w = new WrongCat();
    WrongCat *wrongcat = new WrongCat();
    // //-------------
    // Dog dog1;
    // Dog dog2(dog1);
    // Dog dog3;
    // dog3 = dog2;
    // //-------------


    Animal k(*meta);
    k = *meta;
    std::cout << "j type: " << j->getType() << " " << std::endl;
    std::cout << "i type: " << i->getType() << " " << std::endl;
    std::cout << "Wrongcat type: " << wrongcat->getType() << " " << std::endl;
    
    ((std::cout << "i = "), (i->makeSound()));
    ((std::cout << "j = "), (j->makeSound()));
    ((std::cout << "meta = "), (meta->makeSound()));

    // when the keyword virtual is not being used
    std::cout << "\e[0;31m";
    ((std::cout << "w = "), w->makeSound());

    // only works when declared using WrongCat type
    wrongcat->makeSound();
    std::cout << "\e[m";
    (delete meta, delete j, delete i, delete w, delete wrongcat);
    return 0;
}
