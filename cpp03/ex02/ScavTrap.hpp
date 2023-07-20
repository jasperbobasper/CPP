#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "Claptrap.hpp"

class ScavTrap: public Claptrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &scavtrap);
		~ScavTrap( void );
	public:
		ScavTrap & operator=( ScavTrap const &rhs );
		void	attack(const std::string& target);
		void	guardGate( void );
};

# endif