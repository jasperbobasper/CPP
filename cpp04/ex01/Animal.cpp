#include "Animal.hpp"
Animal::Animal(void)
{
	std::cout << "Animal is constructed" << std::endl;
	return ;
	_type = "Animal";
}
Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor" << std::endl;
	this->_type = src.getType();
	return ;
}
Animal::~Animal(void)
{
	std::cout << "Animal is destroyed" << std::endl;
	return ;
}
Animal	&Animal::operator=(Animal const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "this is a generic animal noise" << std::endl;
}

std::string Animal::getType(void) const
{
	return _type;
}
