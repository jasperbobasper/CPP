#include "Brain.hpp"
Brain::Brain(void)
{
	std::cout << "Brain under construction" << std::endl;
	return ;
}
Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy construction" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	return ;
}
Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
	return ;
}
Brain	&Brain::operator=(Brain const &rhs)
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return *this;
}

void	Brain::setIdeas(std::string thoughts)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = thoughts;
}

std::string* Brain::getIdeas(void)
{
	return (_ideas);
}