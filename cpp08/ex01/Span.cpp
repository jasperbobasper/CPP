#include "Span.hpp"
#include <algorithm>

Span::Span(void) : _N(0)
{
	std::cout << "default constructor called" << std::endl;
	return ;
}
Span::Span(unsigned int N) : _N(N)
{
	std::cout << "standard constructor called" << std::endl;
	return ;
}
Span::Span(Span const &src)
{
	std::cout << "copy constructor called" << std::endl;
	_N = src._N;
	_vct = src._vct;
	*this = src;
	return ;
}
Span::~Span(void)
{
	std::cout << "destructor called" << std::endl;
	return ;
}
Span	&Span::operator=(Span const &rhs)
{
	_N = rhs._N;
	_vct = rhs._vct;
	return *this;
}

void Span::addNumber(int i )
{
	if (_vct.size() < _N)
		_vct.push_back(i);
	else
		throw Span::TooManyElementsException();
}

int	Span::shortestSpan( void )
{
	if (_N < 2)
		throw Span::NoSpanException();
	std::sort(_vct.begin(), _vct.end());
	std::vector<int>::const_iterator it = _vct.begin();
	std::vector<int>::const_iterator ite = _vct.end();
	int span = std::max(*it, *(it + 1)) - std::min(*it, *(it + 1));
	int shortest = span;
	for (it += 1; it + 1 != ite; ++it)
	{
		span = std::max(*it, *(it + 1)) - std::min(*it, *(it + 1));
		shortest = std::min(span, shortest);
	}
	return (shortest);
	return (0);
}

int Span::longestSpan( void ) const
{
	if (_N < 2)
		throw Span::NoSpanException();
	std::vector<int>::const_iterator it = _vct.begin();
	std::vector<int>::const_iterator ite = _vct.end();
	int min = *it;
	int ans = 0;
	for (it = _vct.begin(); it != ite; ++it)
	{
		if (*it < min)
			min = *it;
		else
			ans = std::max(ans, *it - min);
	}
	return (ans);
}

void Span::fillRand(void)
{
	if (_N == 0)
		throw Span::TooManyElementsException();
	int remSize = _N - _vct.size();
	for (int i = 0; i < remSize; i++)
		_vct.push_back(rand() % 100000);
}

void Span::printContents(void)
{
	std::vector<int>::const_iterator it;
	for (it = _vct.begin(); it != _vct.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

const char * Span::TooManyElementsException::what() const throw()
{
	return("Too many elements");
}

const char * Span::NoSpanException::what() const throw()
{
	return("No Span available");
}