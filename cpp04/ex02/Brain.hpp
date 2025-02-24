#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.hpp"

class Brain 
{
    public:
        std::string ideas[100];
        Brain();
        Brain(Brain &copy);
        Brain &operator=(const Brain &copy);
        ~Brain();
};
#endif