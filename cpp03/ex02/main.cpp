#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int main( void )
{
	Claptrap claptrap("Benny");
	ScavTrap scavtrap("Hermann");
	FragTrap fragtrap("Melanie");

	claptrap.attack(scavtrap.getName());
	scavtrap.takeDamage(claptrap.getAttackDamage());
	scavtrap.attack(claptrap.getName());
	claptrap.takeDamage(scavtrap.getAttackDamage());

	fragtrap.attack(scavtrap.getName());
	scavtrap.takeDamage(fragtrap.getAttackDamage());
	scavtrap.beRepaired(20);
	scavtrap.guardGate();
	fragtrap.highFivesGuys();
}