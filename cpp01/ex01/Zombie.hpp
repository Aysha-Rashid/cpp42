#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string.h>
#include <iostream>
class Zombie
{
    private:
        std::string name;
    public:
    	Zombie();
	    ~Zombie();
        void    announce(void);
        void	set_name(std::string local_name);

};
Zombie* zombieHorde(int N, std::string name);

#endif