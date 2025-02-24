#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name + " : Died BraiiiiiiinnnzzzZ" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name + " : BraiiiiiiinnnzzzZ..." << std::endl;
}
void	Zombie::set_name(std::string local_name)
{
	this->name = local_name;
}