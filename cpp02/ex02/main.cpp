#include "Fixed.hpp"

int main( void ) 
{
	Fixed a(10);
	Fixed b(-145.32f);
	Fixed c(42);
	Fixed d = c;
	Fixed e(3.14159f);

	std::cout << "\033[0;36m-- Comparison Operators --\033[0m" << std::endl;
	if (b < a)
		std::cout << b << " < " << a << std::endl;
	if (a > b)
		std::cout << a << " > " << b << std::endl;
	if (a <= b)
		std::cout << a << " <= " << b << std::endl;
	else 
		std::cout << a << " not <= " << b << std::endl;
	if (b >= a)
		std::cout << b << " >= " << a << std::endl;
	else 
		std::cout << b << " not >= " << a << std::endl;
	if (d == c)
		std::cout << d << " == " << c << std::endl;
	if (b != c)
		std::cout << b << " != " << c << std::endl;

	std::cout << "\033[0;36m-- Arithmetic Operators --\033[0m" << std::endl;
	Fixed result;

	result = a + c;
	std::cout << a << " + " << c << " = " << result << std::endl;
	result = b - a;
	std::cout << b << " - " << a << " = " << result << std::endl;
	result = a * e;
	std::cout << a << " * " << e << " = " << result << std::endl;
	result = e / b;
	std::cout << e << " / " << b << " = " << result << std::endl;
	{
		std::cout << "\033[0;36m-- Pre/post increment tests from the subject --\033[0m" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << "\033[0;36m-- Same but with decrements --\033[0m" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::min( a, b ) << std::endl;
	}
}

