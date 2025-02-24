#include "Zombie.hpp"

int main()
{
	randomChump("aysha");
	// stack

	Zombie *hello;
	hello = newZombie("hello");
	hello->announce();
	// heap
	delete hello;
	return 0;
}