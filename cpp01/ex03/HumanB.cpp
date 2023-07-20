#include "HumanB.hpp"

HumanB::HumanB(std::string x)
{
	name = x;
	weapon = NULL;
}

HumanB::~HumanB(void)
{
	//std::cout << name << " has died" << std::endl;
}

void	HumanB::setWeapon(Weapon &wep)
{
	weapon = &wep;
}

void	HumanB::attack(void)
{
	if (weapon != NULL)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else 
		std::cout << name << " does not have a weapon and is unable to attack!" << std::endl;
}