#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") { std::cout << "WrongAnimal Constructor is being called" << std::endl; }
WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "WrongAnimal Copy Constuctor is being called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal Copy Assignment Constructor is Called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal Destructor is being called" << std::endl;}
const std::string WrongAnimal::getType(void) const {return (this->type);}
void WrongAnimal::makeSound(void) const {std::cout << "WrongAnimal sound Nothing" << std::endl;}
