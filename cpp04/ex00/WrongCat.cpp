#include "WrongCat.hpp"
WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat is constructed" << std::endl;
	_type = "WrongCat";
	return ;
}
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = src;
	return ;
}
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat is destroyed" << std::endl;
	return ;
}
WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow. I am a WrongCat" << std::endl;
}
