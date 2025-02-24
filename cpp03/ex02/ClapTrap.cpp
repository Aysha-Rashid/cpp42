#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name) : Name(Name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap Constructor is Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &target)
{
	std::cout << "ClapTrap Copy Constructor is Called" << std::endl;
	*this = target;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
	std::cout << "ClapTrap Copy Assignment Constructor is Called" << std::endl;
	if (this != &ClapTrap)
	{
		this->Name = ClapTrap.Name;
		this->HitPoint = ClapTrap.HitPoint;
		this->EnergyPoint = ClapTrap.EnergyPoint;
		this->AttackDamage = ClapTrap.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor is Called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->EnergyPoint <= 0)
		std::cout << this->Name << " doesn't have enough Energy Point to repaire" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target <<  " causing " << this->AttackDamage << " points of damage! " << std::endl;
		this->EnergyPoint--;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->HitPoint || this->HitPoint <= 0 || this->EnergyPoint <= 0)
		std::cout << this->Name << " is dead" << std::endl;
	else
	{
		this->HitPoint -= amount;
		std::cout << "ClapTrap " << this->Name << " took damage by " << amount << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergyPoint <= 0)
		std::cout << this->Name << " doesn't have enough Energy Point to repaire" << std::endl;
	else
	{
		this->EnergyPoint--;
		this->HitPoint += amount;
		std::cout << "ClapTrap " << this->Name << " repairs itself by " << amount << std::endl;
	}
}
