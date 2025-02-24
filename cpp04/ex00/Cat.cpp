#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat Constructor is being called" << std::endl;
}
Cat::Cat(Cat &copy) : Animal()
{
    std::cout << "Cat Copy Constuctor is being called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat Copy Assignment Constructor is Called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}
void Cat::makeSound(void) const {std::cout << "Cat sound : meow!" << std::endl;}
const std::string Cat::getType(void) const {return (this->type);}
Cat::~Cat() {std::cout << "Cat Destructor is being called" << std::endl;}
