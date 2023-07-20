#include "C.hpp"
C::C(void)
{
	return ;
}
C::C(C const &src)
{
	*this = src;
	return ;
}
C::~C(void)
{
	return ;
}
C	&C::operator=(C const &rhs)
{
	(void)rhs;
	return *this;
}