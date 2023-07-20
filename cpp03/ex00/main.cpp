#include "Claptrap.hpp"

int main( void )
{
	Claptrap claptrap1("Benny");
	Claptrap claptrap2("Pauline");

	claptrap1.attack("the wall");
	claptrap2.attack("god");

	claptrap1.takeDamage(10);
	claptrap2.takeDamage(1);

	claptrap1.beRepaired(12);
	claptrap2.beRepaired(1);
	while (claptrap2.getEnergyPoints() > 0)
		claptrap2.attack("god");
	claptrap2.attack("super god");
}