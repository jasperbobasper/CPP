#include "easyfind.hpp"
#include <list>

int main(void)
{
	std::list<int>	li;

	li.push_back(2);
	li.push_back(4);
	li.push_back(82);
	li.push_back(265);
	li.push_back(26);
	li.push_back(23);

	std::list<int>::iterator re = easyfind(li, 4);
	std::cout << *re << std::endl;
	re = easyfind(li, 26);
	std::cout << *re << std::endl;
	try
	{
		re = easyfind(li, 43);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}