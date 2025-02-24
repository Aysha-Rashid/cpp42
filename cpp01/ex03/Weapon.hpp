#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
// #include "HumanA.hpp"
// #include "HumanB.hpp"

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(const std::string &localType);
		~Weapon();
		const std::string &getType() const;
		void setType(const std::string &newType);
};

#endif
