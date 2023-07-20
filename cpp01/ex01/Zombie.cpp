#include "Zombie.hpp"

Zombie::Zombie(void) 
{
};

Zombie::~Zombie(void)
{
	//std::cout << _name << " has returned to the dead" << std::endl;
};

void	Zombie::setName( std::string name )
{
	_name = name;
};

std::string	Zombie::getName(void)
{
	return(_name);
};

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};