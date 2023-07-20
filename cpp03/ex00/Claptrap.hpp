#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class Claptrap
{
	public:
		Claptrap( void );
		Claptrap( std::string name );
		Claptrap( Claptrap const &claptrap);
		~Claptrap( void );
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
		Claptrap & operator=( Claptrap const &rhs );
		void setHitPoints(unsigned int amount);
		unsigned int getHitPoints( void );
		void setEnergyPoints(unsigned int amount);
		unsigned int getEnergyPoints( void );
		void setAttackDamage(unsigned int amount);
		std::string getName( void );
		void setName(std::string name);
		unsigned int getAttackDamage( void );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

# endif