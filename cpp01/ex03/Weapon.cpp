#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	type = name;
};

Weapon::~Weapon(void)
{
	//std::cout << type << " has been destroyed" << std::endl;
};

std::string const Weapon::getType(void)
{
	return (type);
};

void Weapon::setType(std::string x)
{
	type = x;
};