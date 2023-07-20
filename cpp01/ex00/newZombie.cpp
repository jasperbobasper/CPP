#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie* newArrival = new Zombie(name);
	return (newArrival);
};