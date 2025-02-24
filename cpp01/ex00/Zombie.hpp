#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(const std::string& local_name);
		~Zombie();
		void announce();
};
void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif