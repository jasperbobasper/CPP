#include "Span.hpp"

int main(void)
{

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(15);
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;

	Span sp2 = Span(10000);
	sp2.fillRand();
	std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;

	Span sp3;
	try
	{
		sp3.fillRand();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}