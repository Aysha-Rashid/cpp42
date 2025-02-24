#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	int n = 5;
	int i = 0;
	zombie = zombieHorde(n, "aysha");
	while (n > i)
	{
		zombie[i].announce();
		
		i++;
	}
	delete [] zombie;
	//The delete[] operator should be used only
	// once to deallocate the entire array.
}