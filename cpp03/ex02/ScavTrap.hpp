#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string Name);
        ScavTrap(ScavTrap &target);
        ScavTrap &operator=(const ScavTrap &ClapTrap);
        ~ScavTrap();
        void    attack(const std::string &target);
        void    guardGate();
};
#endif