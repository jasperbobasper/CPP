#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "address of str: " << &str << std::endl;
	std::cout << "address of strPTR: " << &stringPTR << std::endl;
	std::cout << "address of strREF: " << &stringREF << std::endl;
	std::cout << "\nvalue of str: " << str << std::endl;
	std::cout << "\nvalue of strPTR: " << *stringPTR << std::endl;
	std::cout << "\nvalue of strREF: " << stringREF << std::endl;
}