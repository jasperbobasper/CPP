#include "Cat.hpp"
Cat::Cat(void) : Animal()
{
	std::cout << "Cat is constructed" << std::endl;
	_type = "Cat";
}
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = src;
	return ;
}
Cat::~Cat(void)
{
	std::cout << "Cat is destroyed" << std::endl;
	return ;
}
Cat	&Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow. I am a cat." << std::endl;
}
