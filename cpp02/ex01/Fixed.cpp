#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	_fpnValue = 0;
};

Fixed::Fixed( Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};

Fixed::Fixed( int const raw )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpnValue = raw << this->_fBits;
};

Fixed::Fixed( const float raw )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpnValue = roundf(raw * (1 << this->_fBits));
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
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fpnValue);
};

void	Fixed::setRawBits( int const raw )
{
	_fpnValue = raw;
};

float Fixed::toFloat( void ) const
{
	return ((double)this->_fpnValue / (double)(1 << this->_fBits));
};

int Fixed::toInt( void ) const
{
	return (this->_fpnValue >> this->_fBits);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
};
