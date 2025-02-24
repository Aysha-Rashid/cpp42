#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap 
{
    protected:
        std::string Name;
        unsigned int HitPoint;
        unsigned int EnergyPoint;
        unsigned int AttackDamage;
    
    public:
        ClapTrap(std::string Name);
        ClapTrap(ClapTrap &target);
        ClapTrap &operator=(const ClapTrap &ClapTrap);
        ~ClapTrap();
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};
#endif