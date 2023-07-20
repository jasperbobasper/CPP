#include "Claptrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	Claptrap claptrap1("Benny");
	Claptrap claptrap2("Pauline");
	ScavTrap scavtrap1("Hermann");

	claptrap1.attack("the wall");
	claptrap2.attack("god");
	scavtrap1.attack("your mum");

	scavtrap1.guardGate();
	claptrap1.takeDamage(20);
	claptrap1.takeDamage(20);
	claptrap2.takeDamage(1);

	claptrap1.beRepaired(12);
	claptrap2.beRepaired(1);
}