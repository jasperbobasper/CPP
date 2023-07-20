#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string x);
		~HumanB(void);
		void setWeapon(Weapon &wep);
		void attack(void);
	private:
		Weapon *weapon;
		std::string name;
};

# endif