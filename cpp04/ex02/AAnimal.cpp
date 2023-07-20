#include "AAnimal.hpp"
AAnimal::AAnimal(void)
{
	std::cout << "AAnimal is constructed" << std::endl;
	return ;
	_type = "AAnimal";
}
AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal copy constructor" << std::endl;
	this->_type = src.getType();
	return ;
}
AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal is destroyed" << std::endl;
	return ;
}
AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

std::string AAnimal::getType(void) const
{
	return _type;
}
