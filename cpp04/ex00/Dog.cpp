#include "Dog.hpp"
Dog::Dog(void) : Animal()
{
	std::cout << "Dog is constructed" << std::endl;
	_type = "Dog";
	return ;
}
Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = src;
	return ;
}
Dog::~Dog(void)
{
	std::cout << "Dog is destroyed" << std::endl;
	return ;
}
Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof. I am a dog." << std::endl;
}
