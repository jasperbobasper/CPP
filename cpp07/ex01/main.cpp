#include "iter.hpp"
#include <cctype>
#include <cstdlib>

template< typename T > 
void printVal(T &x)
{
	std::cout << "val = " << x << std::endl;
}

int main(void)
{
	int *a = new int[10];

	for (int i = 0; i < 10; i++)
		a[i] = std::rand() % 100;
	::iter(a, 10, &printVal);

	delete [] a;

	std::string strArr[3] = {
		"Wow",
		"Stringy",
		"Array"
	};

	::iter(strArr, 3, &printVal);

}