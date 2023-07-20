#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const &fixed);
		~Fixed( void );
		Fixed & operator=( Fixed const &rhs );
		int	getRawBits( void ) const;
		void setRawBits( int const raw );

	private: 
		int	_fpnValue;
		static const int _fBits = 8;
};

# endif