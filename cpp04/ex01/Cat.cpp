#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat is constructed" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor" << std::endl;
	_brain = new Brain;
	*this->_brain = *src._brain;
	return ;
}
Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat is destroyed" << std::endl;
	return ;
}
Cat	&Cat::operator=(Cat const &rhs)
{
	_brain = rhs._brain;
	this->_type = rhs._type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow. I am a cat." << std::endl;
}

void	Cat::setIdeas(std::string thoughts) const
{
	_brain->setIdeas(thoughts);
}

std::string* Cat::getIdeas(void) const
{
	return(_brain->getIdeas());
}