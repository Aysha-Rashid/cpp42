#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog Constructor is being called" << std::endl;
}
Dog::Dog(Dog &copy) : Animal()
{
    std::cout << "Dog Copy Constuctor is being called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog Copy Assignment Constructor is Called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}
Dog::~Dog() { std::cout << "Dog Destructor is being called" << std::endl;}
const std::string Dog::getType(void) const {return (this->type);}
void Dog::makeSound(void) const {std::cout << "Dog sound : Rouf!" << std::endl;}