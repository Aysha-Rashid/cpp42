#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat &operator=(const Cat &copy);
        Cat(Cat &copy);
        ~Cat();

        const std::string getType() const;
        void makeSound() const;
        void setBrain(std::string ideas, int index);
        void getBrain(int index);
};

#endif