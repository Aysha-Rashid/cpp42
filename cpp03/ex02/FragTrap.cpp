#include "FragTrap.hpp"


FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    this->Name = Name;
    this->HitPoint = 100;
    this->EnergyPoint = 50;
    this->AttackDamage = 20;
    std::cout << "FragTrap Constructor is called" << std::endl;
}

FragTrap::FragTrap(FragTrap &target) : ClapTrap(target)
{
	*this = target;
    std::cout << "FragTrap Copy Constructor is called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
	if (this != &FragTrap)
	{
		this->Name = FragTrap.Name;
		this->HitPoint = FragTrap.HitPoint;
		this->EnergyPoint = FragTrap.EnergyPoint;
		this->AttackDamage = FragTrap.AttackDamage;
	}
    std::cout << "FragTrap Copy Assignement operator is called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor is called" << std::endl;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->Name << " is HighFiving! " << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->EnergyPoint <= 0)
		std::cout << this->Name << " doesn't have enough Energy Point to repaire" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->Name << " attacks " << target <<  " causing " << this->AttackDamage << " points of damage! " << std::endl;
		this->EnergyPoint--;
	}
}