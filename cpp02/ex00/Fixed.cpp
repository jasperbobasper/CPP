#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default contructor called" << std::endl;
	_fpnValue = 0;
};

Fixed::Fixed( Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
};

Fixed &	Fixed::operator=( Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fpnValue = rhs.getRawBits();
	return (*this);
};

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpnValue);
};

void	Fixed::setRawBits( int const raw )
{
	_fpnValue = raw;
};

