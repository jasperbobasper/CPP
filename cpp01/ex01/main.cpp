#include "Zombie.hpp"

int	main(void)
{
	Zombie* horde1 = zombieHorde(2, "In your head");
	Zombie* horde2 = zombieHorde(3, "Zombie");
	Zombie* horde3 = zombieHorde(3, "eh");
	Zombie* horde4 = zombieHorde(-1, "oops");

	delete[] horde1;
	delete[] horde2;
	delete[] horde3;
	return (0);
}