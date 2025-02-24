#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog &operator=(const Dog &copy);
        Dog(Dog &copy);
        ~Dog();
        const std::string getType() const;
        void makeSound() const;
        void getBrain(int index);
        void setBrain(std::string ideas, int index);

};

#endif