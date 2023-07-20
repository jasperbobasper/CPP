#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : Claptrap()
{
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "beep boop a FragTrap named " << _name << " has been created" << std::endl;
};

FragTrap::FragTrap( std::string name ) : Claptrap( name )
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "beep boop a FragTrap named " << name << " has been created" << std::endl;
};

FragTrap::FragTrap( FragTrap const &fragtrap) : Claptrap( fragtrap )
{
	std::cout << "beep boop copy constructor for FragTrap has been activated" << std::endl;
	*this = fragtrap;
};

FragTrap::~FragTrap( void )
{
	std::cout << "beep boop FragTrap " << _name << " has been destroyed :(" << std::endl;
};

FragTrap & FragTrap::operator=( FragTrap const &rhs )
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
};

void	FragTrap::attack(const std::string& target)
{
	if (target == "")
	{
		std::cout << "there is nobody to attack!" << std::endl;
		return ;
	}
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "FragTrap " << _name << " has no energy points and can therefore not attack!" << std::endl;
	else 
		std::cout << "FragTrap " << _name << " is dead and cannot attack!" << std::endl;
};

void	FragTrap::highFivesGuys( void )
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "FragTrap " << _name << " has no energy points and can therefore not high five anyone!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " is dead! No high fives for you :( " << std::endl;
};
