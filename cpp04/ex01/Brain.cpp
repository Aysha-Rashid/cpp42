#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = " is default ";
    std::cout << "Brain Constructor is called" << std::endl;
}

Brain::Brain(Brain &copy)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    std::cout << "Brain Copy Constructor is called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
    std::cout << "Brain Copy Assignment Constructor is Called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    return (*this);
}

Brain::~Brain(){std::cout << "Brain Destructor is called" << std::endl;}