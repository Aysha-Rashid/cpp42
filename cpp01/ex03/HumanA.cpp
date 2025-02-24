#include "HumanA.hpp"

HumanA::HumanA(const std::string &localname, Weapon &localweapon)
    : name(localname), weapon(localweapon)
{
    // the reference must be initialized using Initializer List
}
HumanA::~HumanA()
{

}
void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

// It's generally better to pass strings by const std::string& 
// to avoid unnecessary copying and to ensure the original string is not modified.