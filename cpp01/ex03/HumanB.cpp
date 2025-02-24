#include "HumanB.hpp"

HumanB::HumanB(const std::string& localName)
    : name(localName), weapon(NULL)
{

}
HumanB::~HumanB()
{

}
void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}