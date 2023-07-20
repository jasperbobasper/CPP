#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
	int which = rand() % 3;
	if (which == 0)
		return (new A());
	else if (which == 1)
		return (new B());
	else 
		return (new C());
}

void	identify(Base *p)
{
	A *a;
	if ((a = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	B *b;
	if ((b = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	C *c;
	if ((c = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
	
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
}

int main(void)
{
	std::cout << "Pointer Identify" << std::endl;

	Base *base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << "Reference Identify" << std::endl;
	
	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;
}