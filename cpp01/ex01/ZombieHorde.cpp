#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie = new Zombie[N];
	int i = 0;
	while (N > i)
	{
		zombie[i].set_name(name);
		i++;
	}
	return (zombie);
}
