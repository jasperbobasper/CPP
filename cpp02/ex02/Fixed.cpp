#include "Fixed.hpp"


/*		Constructors and Destructors	 */

Fixed::Fixed( void )
{
	//std::cout << "Default constructor called" << std::endl;
	_fpnValue = 0;
};

Fixed::Fixed( Fixed const &fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};

Fixed::Fixed( int const raw )
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fpnValue = raw << this->_fBits;
};

Fixed::Fixed( const float raw )
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fpnValue = roundf(raw * (1 << this->_fBits));
};

Fixed::~Fixed( void )
{
	//std::cout << "Destructor called" << std::endl;
};


/*		Operator Overloads		*/

Fixed &	Fixed::operator=( Fixed const &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_fpnValue = rhs.getRawBits();
	return (*this);
};

bool Fixed::operator>( Fixed const &rhs )
{
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator<( Fixed const &rhs )
{
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator>=( Fixed const &rhs )
{
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator<=( Fixed const &rhs )
{
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator==( Fixed const &rhs )
{
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
};

bool Fixed::operator!=( Fixed const &rhs )
{
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
};

Fixed Fixed::operator+( Fixed const &rhs )
{
	Fixed result;
	result._fpnValue = this->getRawBits() + rhs.getRawBits();
	return (result);
};

Fixed Fixed::operator-( Fixed const &rhs )
{
	Fixed result;
	result._fpnValue = this->getRawBits() - rhs.getRawBits();
	return (result);
};

Fixed Fixed::operator*( Fixed const &rhs )
{
	Fixed result;

	result._fpnValue = this->getRawBits() * rhs.getRawBits() >> this->_fBits;
	return (result);
};

Fixed Fixed::operator/( Fixed const &rhs )
{
	Fixed result;
	result._fpnValue = (this->getRawBits() << this->_fBits) / rhs.getRawBits();
	return (result);
};

Fixed & Fixed::operator++( void )
{
	_fpnValue++;
	return (*this);
};

Fixed Fixed::operator++( int )
{
	Fixed temp = *this;
	++*this;
	return (temp);
};

Fixed & Fixed::operator--( void )
{
	_fpnValue--;
	return (*this);
};

Fixed Fixed::operator--( int )
{
	Fixed temp = *this;
	--*this;
	return (temp);
};


/*		Member Functions		*/

Fixed & Fixed::min( Fixed &n1, Fixed &n2 )
{
	if (n1.getRawBits() < n2.getRawBits())
		return n1;
	return n2;
};

const Fixed & Fixed::min( Fixed const &n1, Fixed const &n2 )
{
	if (n1.getRawBits() < n2.getRawBits())
		return n1;
	return (n2);
};

Fixed & Fixed::max( Fixed &n1, Fixed &n2 )
{
	if (n1.getRawBits() > n2.getRawBits())
		return n1;
	return n2;
};

const Fixed & Fixed::max( Fixed const &n1, Fixed const &n2 )
{
	if (n1.getRawBits() > n2.getRawBits())
		return n1;
	return (n2);
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


/*		Nonmembers		*/

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
};


