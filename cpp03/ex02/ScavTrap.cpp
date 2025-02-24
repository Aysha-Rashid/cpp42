#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    this->Name = Name;
    this->HitPoint = 100;
    this->EnergyPoint = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Constructor is called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &target) : ClapTrap(target)
{
	*this = target;
    std::cout << "ScavTrap Copy Constructor is called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
	if (this != &ScavTrap)
	{
		this->Name = ScavTrap.Name;
		this->HitPoint = ScavTrap.HitPoint;
		this->EnergyPoint = ScavTrap.EnergyPoint;
		this->AttackDamage = ScavTrap.AttackDamage;
	}
    std::cout << "ScavTrap Copy Assignement operator is called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor is called" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is in Gate Keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->EnergyPoint <= 0)
		std::cout << this->Name << " doesn't have enough Energy Point to repaire" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->Name << " attacks " << target <<  " causing " << this->AttackDamage << " points of damage! " << std::endl;
		this->EnergyPoint--;
	}
}
