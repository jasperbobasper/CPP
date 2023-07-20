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
		float toFloat( void ) const;
		int toInt( void ) const;
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
		static Fixed & min( Fixed &n1, Fixed &n2 );
		static const Fixed & min( Fixed const &n1, Fixed const &n2 );
		static Fixed & max( Fixed &n1, Fixed &n2 );
		static const Fixed & max( Fixed const &n1, Fixed const &n2 );
		Fixed & operator=( Fixed const &rhs );
		bool operator>( Fixed const &rhs );
		bool operator<( Fixed const &rhs );
		bool operator>=( Fixed const &rhs );
		bool operator<=( Fixed const &rhs );
		bool operator==( Fixed const &rhs );
		bool operator!=( Fixed const &rhs );
		Fixed operator+( Fixed const &rhs );
		Fixed operator-( Fixed const &rhs );
		Fixed operator*( Fixed const &rhs );
		Fixed operator/( Fixed const &rhs );
		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

# endif