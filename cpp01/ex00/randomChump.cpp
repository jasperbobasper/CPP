#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie* newArrival = newZombie(name);
	newArrival->announce();
	delete newArrival;
}