#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName( std::string name );
		std::string getName(void);
	private:
		std::string _name;
};

Zombie*	zombieHorde( int N, std::string name );

# endif