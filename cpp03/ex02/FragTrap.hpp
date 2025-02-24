#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string Name);
        FragTrap(FragTrap &target);
        FragTrap &operator=(const FragTrap &ClapTrap);
        ~FragTrap();

        void    attack(const std::string &target);
        void highFivesGuys(void);
        // void    guardGate();
};
#endif