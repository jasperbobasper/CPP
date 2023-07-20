#include "Array.hpp"
#include <cstdlib>

int main(void)
{
	Array<std::string>	strArr;
	Array<int>			intArr(10);

	std::cout << "size of str arr: " << strArr.size() << std::endl;
	std::cout << "size of int arr: " << intArr.size() << std::endl;

	Array<int> cpyArr(intArr);
	for (int i = 0; i < 10; i++)
		intArr[i] = std::rand() % 100;
	for (int i = 0; i < 10; i++)
		cpyArr[i] = std::rand() % 100;
	try
	{
		std::cout << intArr[77] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "intArr[5] = " << intArr[5] << std::endl;
	std::cout << "cpyArr[5] = " <<cpyArr[5] << std::endl;
}