#include "B.hpp"
B::B(void)
{
	return ;
}
B::B(B const &src)
{
	*this = src;
	return ;
}
B::~B(void)
{
	return ;
}
B	&B::operator=(B const &rhs)
{
	(void)rhs;
	return *this;
}
