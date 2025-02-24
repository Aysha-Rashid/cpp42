#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog &operator=(const Dog &copy);
        Dog(Dog &copy);
        ~Dog();
        const std::string getType() const;
        void makeSound() const;
};

#endif