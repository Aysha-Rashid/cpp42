#include "Animal.hpp"

Animal::Animal() : type("") { std::cout << "Animal Constructor is being called" << std::endl; }
Animal::Animal(Animal &copy)
{
    std::cout << "Animal Copy Constuctor is being called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal Copy Assignment Constructor is Called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Animal::~Animal() {std::cout << "Animal Destructor is being called" << std::endl;}
const std::string Animal::getType(void) const {return (this->type);}
void Animal::makeSound(void) const {std::cout << "Animal sound Nothing" << std::endl;}