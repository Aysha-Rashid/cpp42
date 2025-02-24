#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongCat();
        WrongCat(WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
        virtual ~WrongCat();
        const std::string getType() const;
        void makeSound() const;
};

#endif
