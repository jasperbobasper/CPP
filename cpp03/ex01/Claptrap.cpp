#include "Claptrap.hpp"

Claptrap::Claptrap( void )
{
	_name = "default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "beep boop a claptrap named " << _name << " has been created" << std::endl;
};

Claptrap::Claptrap( std::string name )
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "beep boop a claptrap named " << name << " has been created" << std::endl;
};

Claptrap::Claptrap( Claptrap const &claptrap)
{
	std::cout << "beep boop copy constructor has been activated" << std::endl;
	*this = claptrap;
};

Claptrap::~Claptrap( void )
{
	std::cout << "beep boop " << _name << " has been destroyed :(" << std::endl;
};

Claptrap & Claptrap::operator=( Claptrap const &rhs )
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
};

void Claptrap::setHitPoints(unsigned int amount)
{
	_hitPoints = amount;
};

unsigned int Claptrap::getHitPoints( void )
{
	return(_hitPoints);
};

void Claptrap::setEnergyPoints(unsigned int amount)
{
	_energyPoints = amount;
};

unsigned int Claptrap::getEnergyPoints( void )
{
	return(_energyPoints);
};

void Claptrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
};

unsigned int Claptrap::getAttackDamage( void )
{
	return(_attackDamage);
};

std::string Claptrap::getName( void )
{
	return (_name);
};

void Claptrap::setName(std::string name)
{
	_name = name;
};

void	Claptrap::attack(const std::string& target)
{
	if (target == "")
	{
		std::cout << "there is nobody to attack!" << std::endl;
		return ;
	}
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no energy points and can therefore not attack!" << std::endl;
	else 
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
};

void	Claptrap::takeDamage(unsigned int amount)
{
	if (_hitPoints < 0)
	{
		std::cout << _name << " is already dead! You can stop now!" << std::endl;
		return;
	}
	_hitPoints -= amount;
	if ( _hitPoints <= 0)
		std::cout << _name << " takes " << amount << " points of damage and dies! :( " << std::endl;
	else
		std::cout  << _name << " takes " << amount << " of damage and is left with " << this->_hitPoints << " hitpoints!" << std::endl;
};

void	Claptrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << _name << " repairs itself for " << amount << " hp! Bringing it's total hp up to " << _hitPoints << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << _name << " has no energy points and can therefore not repair itself!" << std::endl;
	else
		std::cout << _name << " is dead! It's too late for repairs now. " << std::endl;
};
