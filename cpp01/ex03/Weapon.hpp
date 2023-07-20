#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>


class Weapon
{
	public:
		Weapon(std::string name);
		~Weapon(void);
		std::string const getType(void);
		void setType(std::string x);
	private:
		std::string type;
};

#endif