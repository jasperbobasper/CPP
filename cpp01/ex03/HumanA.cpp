#include "HumanA.hpp"	

HumanA::HumanA(std::string x, Weapon& wep)
{
	name = x;
	weapon = &wep;
};

HumanA::~HumanA(void)
{
	//std::cout << name << " has died" << std::endl;
};

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
};