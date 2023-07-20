#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal is constructed" << std::endl;
	_type = "WrongAnimal";
	return ;
}
WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = src;
	return ;
}
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal is destroyed" << std::endl;
	return ;
}
WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs._type;
	return *this;
}
void WrongAnimal::makeSound(void) const
{
	std::cout << "this is a generic WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}