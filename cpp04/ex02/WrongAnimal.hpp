#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);
        virtual ~WrongAnimal();
        const std::string getType() const;
        void makeSound() const;
};

#endif

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

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
