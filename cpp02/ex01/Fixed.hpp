#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed( int const raw );
		Fixed( const float raw );
		Fixed( Fixed const &fixed);
		~Fixed( void );

	private: 
		int	_fpnValue;
		static const int _fBits = 8;

	public:
		Fixed & operator=( Fixed const &rhs );
		float toFloat( void ) const;
		int toInt( void ) const;
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

# endif