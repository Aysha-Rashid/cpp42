#include "ClapTrap.hpp"

int main()
{
    ClapTrap Name("aysha");

    int i  = 10;
    while(i > 0)
    {
        Name.attack("bruh");
        Name.beRepaired(15);
        Name.takeDamage(15);
        i--;
    }
}
