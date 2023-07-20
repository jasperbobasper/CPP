#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : Claptrap()
{
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "beep boop a ScavTrap named " << _name << " has been created" << std::endl;
};

ScavTrap::ScavTrap( std::string name ) : Claptrap( name )
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "beep boop a ScavTrap named " << name << " has been created" << std::endl;
};

ScavTrap::ScavTrap( ScavTrap const &scavtrap) : Claptrap( scavtrap )
{
	std::cout << "beep boop copy constructor for ScavTrap has been activated" << std::endl;
	*this = scavtrap;
};

ScavTrap::~ScavTrap( void )
{
	std::cout << "beep boop ScavTrap " << _name << " has been destroyed :(" << std::endl;
};

ScavTrap & ScavTrap::operator=( ScavTrap const &rhs )
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
};

void	ScavTrap::attack(const std::string& target)
{
	if (target == "")
	{
		std::cout << "there is nobody to attack!" << std::endl;
		return ;
	}
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap " << _name << " has no energy points and can therefore not attack!" << std::endl;
	else 
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
};

void	ScavTrap::guardGate( void )
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " is now in gatekeeper mode!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap " << _name << " has no energy points and can therefore not enter gatekeeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is dead! Now you cannot gaslight, gatekeep or girlboss :( " << std::endl;
};
