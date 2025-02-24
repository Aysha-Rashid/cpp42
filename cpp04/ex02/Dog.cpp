#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->brain = new Brain();
    std::cout << "Dog Constructor is being called" << std::endl;
    this->type = "Dog";
}
Dog::Dog(Dog &copy) : Animal()
{
    std::cout << "Dog Copy Constuctor is being called" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
        this->brain = new Brain (*copy.brain);
    }
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog Copy Assignment Constructor is Called" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain (*copy.brain);
    }
    return (*this);
}

void Dog::setBrain(std::string ideas, int index)
{
    if (index >= 0 && index < 100)
        this->brain->ideas[index] = ideas;
    else
        std::cout << "invalid index" << std::endl;
}

void Dog::getBrain(int index)
{
    if (index >= 0 && index < 100)
        std::cout << "ideas of Dog" << index << this->brain->ideas[index] << std::endl;
    else
        std::cout << "invalid index" << std::endl;
}
Dog::~Dog() { delete this->brain; std::cout << "Dog Destructor is being called" << std::endl;}
const std::string Dog::getType(void) const {return (this->type);}
void Dog::makeSound(void) const {std::cout << "Dog sound : Rouf!" << std::endl;}