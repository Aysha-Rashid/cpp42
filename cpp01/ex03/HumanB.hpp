#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;  // Pointer to allow no weapon initially

	public:
		HumanB(const std::string &localName);
		~HumanB();
		void setWeapon(Weapon &newWeapon);
		void attack() const;
};

#endif
