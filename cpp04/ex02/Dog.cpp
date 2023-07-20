#include "Dog.hpp"
Dog::Dog(void) : AAnimal()
{
	std::cout << "Dog is constructed" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	return ;
}
Dog::Dog(Dog const &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor" << std::endl;
	_brain = new Brain;
	*this->_brain = *src._brain;
	return ;
}
Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog is destroyed" << std::endl;
	return ;
}
Dog	&Dog::operator=(Dog const &rhs)
{
	_brain = rhs._brain;
	this->_type = rhs._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof. I am a dog." << std::endl;
}

void	Dog::setIdeas(std::string thoughts) const
{
	_brain->setIdeas(thoughts);
}

std::string* Dog::getIdeas(void) const
{
	return(_brain->getIdeas());
}

